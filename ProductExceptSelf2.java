package com.wrh.leetcode;

public class ProductExceptSelf2 {
	
    public int[] productExceptSelf(int[] nums) {
    	if(nums==null){
    		return null;
    	}
    	int len = nums.length;
    	if(len==1){
    		return nums;
    	}
    	/*
    	 * proudctLeft[i]用来记录位置为i左边所有数的乘积
    	 * productRight[i]用来记录位置为i右边所有数的乘积
    	 * */
        int[] productLeft=new int[len];
        int[] productRight=new int[len];
        productLeft[0]=1;//最左边的一位没有数，这里初始化为1
        for(int i=1;i<len;i++){
        	productLeft[i] = nums[i-1]*productLeft[i-1];
        }
        
        productRight[len-1]=1;//最后一位的右边没有数，这里初始化为1
        for(int i=len-1;i>0;i--){
        	productRight[i-1] = nums[i]*productRight[i];
        }
        //productLeft[i]*productRight[i]就是除第i位数所有数的乘积
        int[] res = new int[len];
        for(int i=0;i<len;i++){
        	res[i]=productLeft[i]*productRight[i];
        }
        return res;      
    }	
}
