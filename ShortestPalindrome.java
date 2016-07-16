package com.wrh.leetcode;

public class ShortestPalindrome {
	
    public String shortestPalindrome(String s) {
        if(s==null||s.length()<1||isPalindrome(s)){
        	return s;
        }
        //如果s不是回文字符，则在字符串前面添加字符使其为回文字符串
        int len = s.length();
        String ss = s;
        for(int i=len-1;i>=0;i--){
            s = s.substring(0, len-1-i)+ss.charAt(i)+s.substring(len-1-i);
        	if(isPalindrome(s)){
        		return s;
        	}
        }
        return s;
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
	
	public static void main(String[] args){
		String str = "aabcd";
		String res = new ShortestPalindrome().shortestPalindrome(str);
		System.out.println(res);
	}
}
