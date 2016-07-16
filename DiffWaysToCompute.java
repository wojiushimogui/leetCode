package com.wrh.leetcode;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class DiffWaysToCompute {
	
    public List<Integer> diffWaysToCompute(String input) {
        //Set<Integer> set = new HashSet<Integer> ();
    	List<Integer> res = new ArrayList<Integer> ();
        int len = input.length();
        for(int i=0;i<len;i++){
        	char ch = input.charAt(i);
        	if(ch=='+'||ch=='-'||ch=='*'){
        		String part1 = input.substring(0, i);
        		String part2 = input.substring(i+1);
        		List<Integer> partRes=diffWaysToCompute(part1);
        		List<Integer> partRes2=diffWaysToCompute(part2);
        		for(Integer val:partRes){
        			for(Integer val2:partRes2){
        				int tempRes = 0;
        				switch(ch){
        				case '+':
        					tempRes = val+val2;
        					break;
        				case '-':
        					tempRes = val-val2;
        					break;
        				case '*':
        					tempRes = val*val2;
        					break;
        				}
        			//set.add(tempRes);	
        			res.add(tempRes);
        			}
        		}
        	}
        }
        if(res.size()==0){//如果没有结果，则说明此字符串为一个数
        	res.add(Integer.valueOf(input));
        }
        return res;
    }
}
