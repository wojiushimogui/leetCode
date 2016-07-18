package com.wrh.leetcode;

public class MoveZeroes {
	
    public void moveZeroes(int[] nums) {
        int len = nums.length;
        int begin = 0;
        for(int i=0;i<len;i++){
        	if(nums[i]!=0){
        		nums[begin]=nums[i];
        		begin++;
        	}
        }
        for(;begin<len;begin++){
        	nums[begin]=0;
        }
    }
}
