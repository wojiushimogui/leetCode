package com.wrh.leetcode;

public class ShortestPalindrome3 {
	
    public String shortestPalindrome(String s) {
        if(s==null||s.length()<1){
        	return s;
        }
        //
        int len = s.length();
        int j = 0;
        for(int i=len-1;i>=0;i--){
        	if(s.charAt(i)==s.charAt(j)){
        		j++;
        	}
        }
        
        if(j == len){//本身就是回文字符串
        	return s;
        }
        String suffix = s.substring(j);
        return new StringBuilder(suffix).reverse()+shortestPalindrome(s.substring(0, j))+suffix;

    }
}
