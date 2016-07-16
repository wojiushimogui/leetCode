package com.wrh.leetcode;

public class LongestPalindrome3 {
	int lowIndex = -1;
	int maxLen = -1;
	
    public String longestPalindrome(String s) {
        
    	if(s==null||s.length()<2){
    		return s;
    	}
    	int len =s.length();
   	
    	for(int i=0;i<len-1;i++){
    		//找出以i为中心的最大回文字符串
    		extendsPalindrome(s,i,i);//assume odd number
    		extendsPalindrome(s,i,i+1);//assume even number
    	}
    	return s.substring(lowIndex, lowIndex+maxLen);
    }
    private void extendsPalindrome(String s, int i, int j) {
    	if(s==null||i>j){
    		return ;
    	}
    	while(i>=0&&i<=j&&j<s.length()&&s.charAt(i)==s.charAt(j)){
    		i--;
    		j++;
    	}
    	int len = (j-1)-(i+1)+1;
    	if(maxLen<len){
    		lowIndex = i+1;
    		maxLen = len;
    	}
	}
	public static void main(String[] args){
		String str = "111";
		String res = new LongestPalindrome3().longestPalindrome(str);
		System.out.println(res);
		
	}
}
