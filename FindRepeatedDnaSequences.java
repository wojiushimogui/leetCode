package com.wrh.leetcode;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class FindRepeatedDnaSequences {
	
	public List<String> findRepeatedDnaSequences(String s) {
        Set<String> set=new HashSet<String>();
        int len=s.length();
        int sLen=10;
        for(int i=0;i<len-sLen;i++){
        	String str=s.substring(i, i+sLen);
        	boolean isExist=isExist(str,s.substring(i+1));
        	if(isExist){
        		set.add(str);
        	}
        }
		List<String> list=new ArrayList<String>();
		for(String str:set){
			list.add(str);
		}
		return list;
    }
	public boolean isExist(String s,String str){	
		return str.contains(s);
	}
	public static void main(String []args){
		FindRepeatedDnaSequences f=new FindRepeatedDnaSequences();
		String s="AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
		List<String> list=f.findRepeatedDnaSequences(s);
		for(String str:list){
			System.out.println(str);
		}
		
	}
}
