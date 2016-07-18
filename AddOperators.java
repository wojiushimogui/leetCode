package com.wrh.leetcode;

import java.util.ArrayList;
import java.util.List;

public class AddOperators {
	
	private String num;
	private int target;
	
    public List<String> addOperators(String num, int target) {
       List<String> res = new ArrayList<String>();
       int len = num.length();
       if(len==0){
    	   return res;
       }
       this.num = num;
       this.target = target;
       addOperatorsHelper(res,"",0,0,0);
       return res;
    }
	private void addOperatorsHelper(List<String> res, String path,
			 int pos, long eval, long mult) {
		if(pos==num.length()){
			if(eval==target){
				res.add(path);
			}
			return;
		}
		for(int i=pos;i<num.length();i++){
			if(i!=pos&&num.charAt(pos)=='0'){//多位数的第一位数不能为0
				break;
			}
			Long cur = Long.parseLong(num.substring(pos, i+1));
			if(pos==0){
				addOperatorsHelper(res,path+cur,i+1,cur,cur);
			}
			else{
				addOperatorsHelper(res,path+"+"+cur,i+1,eval+cur,cur);
				addOperatorsHelper(res,path+"-"+cur,i+1,eval-cur,-cur);//注意这里是负cur
				addOperatorsHelper(res,path+"*"+cur,i+1,eval-mult+cur*mult,cur*mult);
			}
		}
		
	}


}
