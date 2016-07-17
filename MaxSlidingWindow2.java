package com.wrh.leetcode;

public class MaxSlidingWindow2 {
	
    public int[] maxSlidingWindow(int[] nums, int k) {
    	if(nums==null||nums.length<k||k<1){
    		return new int[0];
    	}
    	int len = nums.length;
        int[] res = new int[len-k+1];
        for(int i=0;i<len-k+1;i++){
        	if(i==0){
        		res[i]=maxValue(nums,i,i+k-1);
        	}
        	else{
        		int temp = nums[i];
        		int pre = nums[i-k];
        		res[i] = (temp>=res[i-1]?temp:
        			(res[i-1]!=pre?res[i-1]:maxValue(nums,i,i+k-1)));
        	}
        	
        }
        return res;
    }

	private int maxValue(int[] nums, int begin, int end) {
		if(nums==null||begin>end){
			return Integer.MIN_VALUE;
		}
		int max = Integer.MIN_VALUE;
		for(int i=begin;i<=end;i++){
			if(max<nums[i]){
				max = nums[i];
			}
		}
		return max;
	}
}
