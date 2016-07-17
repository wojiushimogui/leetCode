package com.wrh.leetcode;

public class ShortestPalindrome2 {
	
    public String shortestPalindrome(String s) {
        if(s==null||s.length()<1||isPalindrome(s)){
        	return s;
        }
        //���s���ǻ����ַ��������ַ���ǰ������ַ�ʹ��Ϊ�����ַ���
        int len = s.length();
        String str =new String();
        int i = len;
        for(;i>=0;i--){
        	str = s.substring(0, i);
        	if(isPalindrome(str)){
        		break;
        	}
        }
        String ss = s.substring(i);
        StringBuilder sb = new StringBuilder(ss);
        return sb.reverse().append(str).append(ss).toString();
    }
    //�ж�һ���ַ����Ƿ���palindrome
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
		String str = "adv";
		String res = new ShortestPalindrome2().shortestPalindrome(str);
		System.out.println(res);
	}
}
