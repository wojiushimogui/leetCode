package com.wrh.leetcode;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;

public class FindRepeatedDnaSequences_v1 {
	
	public List<String> findRepeatedDnaSequences(String s) {
        Map<String,Integer> map=new HashMap<String,Integer>();
        int len=s.length();
        int sLen=10;
        for(int i=0;i<=len-sLen;i++){//注意边界
        	String str=s.substring(i, i+sLen);//最后的索引位置是取不到的
        	Integer count=map.getOrDefault(str, 0);
        	count++;
        	map.put(str, count);
        }
		List<String> list=new ArrayList<String>();
		Set<String> set=map.keySet();
		for(String str:set){
			int count=map.get(str);
			if(count>1){
				list.add(str);
			}
		}
		return list;
    }
	public static void main(String []args){
		FindRepeatedDnaSequences_v1 f=new FindRepeatedDnaSequences_v1();
//		String s="AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
		String s="AAAAAAAAAAA";
		List<String> list=f.findRepeatedDnaSequences(s);
		for(String str:list){
			System.out.println(str);
		}
		
	}
}
