package com.wrh.leetcode;

public class LongestPalindrome {
	
    public String longestPalindrome(String s) {
        
    	if(s==null||s.length()<2){
    		return s;
    	}
    	int len =s.length();
    	
    	String res = new String();
    	
    	for(int i=0;i<len;i++){
    		char ch = s.charAt(i);
    		for(int j=i+1;j<len;j++){
    			char ch2 = s.charAt(j);
    			if(ch==ch2){
    				String str = s.substring(i, j+1);//
    				if(isPalindrome(str)){
    					if(str.length()>res.length()){
    						res = str;
    					}
    				}
    			}
    		}
    	}
    	return res;
    }
    //判断一个字符串是否是palindrome
	private boolean isPalindrome(String str) {
		if(str==null||str.length()<1){
			return false;
		}
		int begin = 0;
		int end = str.length()-1;
		while(begin<end){
			if(str.charAt(begin)!=str.charAt(end)){
				return false;
			}
			begin++;
			end--;
		}
		
		return true;
	}	
}
