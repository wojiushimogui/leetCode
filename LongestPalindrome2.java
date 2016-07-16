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
    		//���ݴ�ʱ��res������j�ķ�Χ
    		for(int j=len-1;j>=i+res.length();j--){
    			char ch2 = s.charAt(j);
    			if(ch==ch2){
    				String str = s.substring(i, j+1);//
    				if(isPalindrome(str)){
    						//�����ʱstrΪ���ģ��򳤶�һ�����ڴ�ʱ��res����˲���Ҫ�жϾͿ��Խ��и���
    						res = str;
    						break;
    				}
    			}
    		}
    	}
    	return res;
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
		String str = "123214";
		String res = new LongestPalindrome2().longestPalindrome(str);
		System.out.println(res);
		
	}
}
