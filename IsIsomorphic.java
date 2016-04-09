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
        	if(ch=='\0'){//��һ�γ��֣��򱣴�
        		//����֮ǰҪ��飬��ֵ�е�ֵ�Ƿ�Ψһ�������ܶ����ͬ�ļ�ӳ�䵽һ��ֵ
        		char tempCh=t.charAt(i);
        		if(map.containsValue(tempCh)){
        			return false;
        		}
        		map.put(s.charAt(i),tempCh);//ֻ�м���ֵ��û�г��֣��ż���map
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
