package com.wrh.leetcode;

import java.util.ArrayList;
import java.util.List;
/*题目：
 * Given a string containing only digits, 
 * restore it by returning all possible valid IP address combinations.
 * */
public class Solution_6 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}
	/*
	 * the basic idea is to make three cuts into the string, 
	 * separating it into four parts, each part contains 1~3 digits and it must be <255.
	 * */
	public List<String> restoreIpAddresses(String s) {
        if(s.length()<4){
        	return null;
        }
        List<String> result=new ArrayList<String>();
        int len=s.length();
        for(int i=1;i<=3;i++){//切第一刀
        	if(len-i>9) continue;
        	for(int j=i+1;j<=i+3;j++){
        		if(len-j>6) continue;
        		for(int k=j+1;k<=j+3&&k<len;k++){
        			if(len-k>3) continue;
        			//看看此时切出来的几个部分是否满足数字<=255,如果满足条件
        			int a,b,c,d;
        			 a=Integer.parseInt(s.substring(0,i));
        			 b=Integer.parseInt(s.substring(i, j));
        			 c=Integer.parseInt(s.substring(j, k));
        			 d=Integer.parseInt(s.substring(k, len));
        			 if(a>255||b>255||c>255||d>255) continue;
        			 String res=a+"."+b+"."+c+"."+d;
        			 if(res.length()<len+3) continue;//不允许出现这样的情况："01"----->1;例如s="10000"时，只能有10.0.0.0这个结果
        			 result.add(res);
        			
        		}
        	}
        }
        return  result;
		
    }

//https://leetcode.com/discuss/19296/my-concise-ac-java-code	

}
