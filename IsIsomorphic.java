package com.wrh.leetcode;

import java.util.HashMap;
import java.util.Map;

public class IsIsomorphic {
	
	public boolean isIsomorphic(String s, String t) {
		if(s==null&&t==null){
			return true;
		}
        int len1=s.length();
        int len2=t.length();
        if(len1!=len2){
        	return false;
        }
        Map<Character,Character> map=new HashMap<Character,Character>();
        StringBuffer sb=new StringBuffer();
        for(int i=0;i<len1;i++){
        	char ch=map.getOrDefault(s.charAt(i), '\0');
        	if(ch=='\0'){//第一次出现，则保存
        		//保存之前要检查，键值中的值是否唯一，即不能多个不同的键映射到一个值
        		char tempCh=t.charAt(i);
        		if(map.containsValue(tempCh)){
        			return false;
        		}
        		map.put(s.charAt(i),tempCh);//只有键和值都没有出现，才加入map
        		sb.append(tempCh);
        	}
        	else{
        		sb.append(ch);
        	}
        	
        }
        if(t.equals(sb.toString())){
        	return true;
        }
		return false;
    }
}
