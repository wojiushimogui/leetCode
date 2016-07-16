package com.wrh.leetcode;

public class ProductExceptSelf {
	
    public int[] productExceptSelf(int[] nums) {
    	if(nums==null){
    		return null;
    	}
    	if(nums.length==1){
    		return nums;
    	}
        int[] input=new int[nums.length];
        for(int i=0;i<nums.length;i++){
        	int product = 1;
        	for(int j =0;j<nums.length;j++){
        		if(i==j){
        			continue;
        		}
        		product*=nums[j];
        	}
        	input[i]=product;
        }
        return input;      
    }	
}
