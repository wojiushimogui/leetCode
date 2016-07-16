package com.wrh.leetcode;

import java.util.Set;
import java.util.SortedSet;
import java.util.TreeSet;

public class ContainsNearbyAlmostDuplicate {
	
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {  
        if(nums==null||k<0){
        	return false;
        }
        SortedSet<Long> set = new TreeSet<Long> ();
        for(int i=0;i<nums.length;i++){
        	SortedSet<Long> s = set.subSet((long)nums[i]-t, (long)nums[i]+t+1);
        	if(!s.isEmpty()){
        		return true;
        	}
        	if(k<=i){
        		set.remove((long)nums[i-k]);
        	}
        	set.add((long)nums[i]);
        	
        }
        return false;
    }  
	
	public static void main(String[] args){
		int [] nums ={-1,2147483647};
		int k = 1;
		int t = 2147483647;
		long r = nums[1]-nums[0];
		System.out.println(Math.abs(r));
		boolean res = new ContainsNearbyAlmostDuplicate().containsNearbyAlmostDuplicate(nums,k,t);
		System.out.println(res);
	}
}
