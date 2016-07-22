package com.wrh.leetcode;

import java.util.ArrayList;

public class AdditiveNumber {
	
    public boolean isAdditiveNumber(String num) {
        return help(num,new ArrayList<Integer>(),0);
    }

	private boolean help(String num, ArrayList<Integer> res, int pos) {
		if(pos==num.length()){
			int size = res.size();
			if(size>=3){
				if(res.get(size-1)==res.get(size-2)+res.get(size-3)){
					return true;
				}
			}
		}
		for(int i=pos;i<num.length();i++){
			if(i!=pos&&Integer.valueOf(num.charAt(i))==0){//多位数的开头不能为零
				continue;
			}
			int val = Integer.valueOf(num.substring(pos, i+1));
			int size = res.size();
			if(size<3){
				res.add(val);
				return help(num, res,i+1);
			}
			else{
				if(res.get(size-1)==res.get(size-2)+res.get(size-3)){
					return help(num, res,i+1);
				}
			}
		}
		
		return false;
	}
}
