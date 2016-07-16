package com.wrh.leetcode;

public class Anagram {
	//ͳ��s��t�г��ֵ��ַ��ĸ����Ƿ�һ��
    public boolean isAnagram(String s, String t) {
    	if(s.length()!=t.length()){
    		return false;
    	}
    	int len =26;
        int[] countInS = new int[len];
        int[] countInT = new int[len];
        for(int i=0;i<len;i++){
        	countInS[i]=0;
        	countInT[i]=0;
        }
        for(int i=0;i<s.length();i++){
        	countInS[s.charAt(i)-'a']++;
        	countInS[t.charAt(i)-'a']++;
        }
        
        for(int i=0;i<s.length();i++){
        	if(countInS[i]!=countInT[i]){
        		return false;
        	}
        }
        return true;
    }
}
