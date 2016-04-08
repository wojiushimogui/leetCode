package com.wrh.leetcode;

import java.util.HashSet;
import java.util.Set;

public class WordPattern {
	
	public boolean wordPattern(String pattern, String str) {
        String []s=str.split(" ");
        char []chArr=pattern.toCharArray();
        int len=chArr.length;
        if(s.length!=len){//������Ȳ���ȣ���϶�����ƥ���ģʽ��
        	return false;
        }
        int start=0;
        int end=len-1;
        while(start<end){
        	if((chArr[start]==chArr[end]&&s[start].equals(s[end])||(chArr[start]!=chArr[end]&&!s[start].equals(s[end])))){//Ҫô����ȣ�Ҫô�������
        		start++;
        		end--;
        	}
        	else{
        		return false;
        	}
        }
        Set<Character> set=new HashSet<Character> ();
        for(char ch:chArr){
        	set.add(ch);
        }
        Set<String> set1=new HashSet<String>();
        for(String ss:s){
        	set1.add(ss);
        }
        if(set1.size()==set.size()){
        	return true;
        }
		return false;
    }
}
