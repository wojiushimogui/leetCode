package com.wrh.leetcode;

public class ConvertToTitle {
	public String convertToTitle(int n) {
       if(n<1){
    	   return null;
       }
       char []alph="ZABCDEFGHIJKLMNOPQRSTUVWXY".toCharArray();
       StringBuffer sb=new StringBuffer();
       while(n!=0){
    	   int temp=n%26;
    	   sb.insert(0, alph[temp]);
    	   if(temp==0){
    		   n-=26;
    	   }
    	   n/=26;
       }
       return sb.toString();
    }
	public int titleToNumber(String s) {
        if(s==null){
        	return 0;
        }
        int len=s.length();
        int res=0;
        for(int i=0;i<len;i++){
        	int temp=s.charAt(i)-'A'+1;
        	res=res*26+temp;
        }
		return res;
    }
	public boolean isPowerOfTwo(int n) {
        return n>0&&((n&(n-1))==0);
    }
	public boolean isPowerOfThree(int n) {
        if(n<=0){
        	return false;
        }
        int max3PowerValue= 1162261467; // 3^19,
        int maxInt= 1162261467; // 2^31-1;
        return max3PowerValue%n==0;		
    }
}
