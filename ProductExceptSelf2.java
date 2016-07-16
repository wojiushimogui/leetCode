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
    	 * proudctLeft[i]������¼λ��Ϊi����������ĳ˻�
    	 * productRight[i]������¼λ��Ϊi�ұ��������ĳ˻�
    	 * */
        int[] productLeft=new int[len];
        int[] productRight=new int[len];
        productLeft[0]=1;//����ߵ�һλû�����������ʼ��Ϊ1
        for(int i=1;i<len;i++){
        	productLeft[i] = nums[i-1]*productLeft[i-1];
        }
        
        productRight[len-1]=1;//���һλ���ұ�û�����������ʼ��Ϊ1
        for(int i=len-1;i>0;i--){
        	productRight[i-1] = nums[i]*productRight[i];
        }
        //productLeft[i]*productRight[i]���ǳ���iλ���������ĳ˻�
        int[] res = new int[len];
        for(int i=0;i<len;i++){
        	res[i]=productLeft[i]*productRight[i];
        }
        return res;      
    }	
}
