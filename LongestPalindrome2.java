package com.wrh.leetcode;

public class LongestPalindrome2 {
	
    public String longestPalindrome(String s) {
        
    	if(s==null||s.length()<2){
    		return s;
    	}
    	int len =s.length();
    	
    	String res = new String();
    	
    	for(int i=0;i<len;i++){
    		char ch = s.charAt(i);
    		//根据此时的res来限制j的范围
    		for(int j=len-1;j>=i+res.length();j--){
    			char ch2 = s.charAt(j);
    			if(ch==ch2){
    				String str = s.substring(i, j+1);//
    				if(isPalindrome(str)){
    						//如果此时str为回文，则长度一定大于此时的res，因此不需要判断就可以进行更新
    						res = str;
    						break;
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
	public static void main(String[] args){
		String str = "123214";
		String res = new LongestPalindrome2().longestPalindrome(str);
		System.out.println(res);
		
	}
}
