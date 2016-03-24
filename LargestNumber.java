package com.wrh.leetcode;

import java.util.Arrays;
import java.util.Comparator;

public class LargestNumber {
	
	public String largestNumber(int[] nums) {
        if(nums==null||nums.length<1){
        	return null;
        }
        //����
        int len=nums.length;
        String [] strs=new String[len];
        for(int i=0;i<len;i++){
        	strs[i]=Integer.toString(nums[i]);
        }
        Arrays.sort(strs, new Comparator<String>(){
			@Override
			public int compare(String str1, String str2) {
				StringBuilder sb=new StringBuilder();
				StringBuilder sb2=new StringBuilder();
				sb.append(str1).append(str2);
				sb2.append(str2).append(str1);				
				return sb2.toString().compareTo(sb.toString());
			}
        	
        });
        //�������Ľ����������ͺ�
        if(strs[len-1].charAt(0)=='0'){//������λ��Ϊ0���򷵻�0
        	return "0";
        }
        StringBuffer sb=new StringBuffer();
        for(int i=len-1;i>=0;i--){
        	sb.append(strs[i]);
        }
		return sb.toString();
    }
}
