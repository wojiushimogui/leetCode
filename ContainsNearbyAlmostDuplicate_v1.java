package com.wrh.leetcode;

public class ContainsNearbyAlmostDuplicate_v1 {
	
	public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        for(int i=0;i<nums.length;i++){
        	for(int j=i+1;j<i+k&&j<nums.length;j++){
        		if(Math.abs(nums[i]-nums[j])<=t){
        			return true;
        		}
        	}
        }
        return false;
    }
	
	public static void main(String[] args){
		int [] nums ={-1,2147483647};
		int k = 1;
		int t = 2147483647;
		long r = nums[1]-nums[0];
		System.out.println(Math.abs(r));
		boolean res = new ContainsNearbyAlmostDuplicate_v1().containsNearbyAlmostDuplicate(nums,k,t);
		System.out.println(res);
	}
}
