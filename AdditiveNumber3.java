package com.wrh.leetcode;

import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.List;

//考虑大数
public class AdditiveNumber3 {
	
	private List<List<BigDecimal>> allRes = new ArrayList<List<BigDecimal>>();
    public boolean isAdditiveNumber(String num) {
        help(num,new ArrayList<BigDecimal>(),0);  
        return allRes.size()>0;
       
    }

	private void help(String num, ArrayList<BigDecimal> res, int pos) {
		if(pos==num.length()){//
			int size = res.size();
			if(size>=3){
				if(res.get(size-1).subtract(res.get(size-2)).equals(res.get(size-3))){//这个判断可以不要
					allRes.add(res);
				}
			}
		}
		for(int i=pos;i<num.length();i++){
			if(i!=pos&&num.charAt(pos)=='0'){//多位数的开头不能为零
				break;
			}
			BigDecimal val = new BigDecimal(num.substring(pos, i+1));
			int size = res.size();	
			if(size<2){		
				res.add(val);
				help(num, new ArrayList(res),i+1);
				res.remove(res.get(res.size()-1));//将最后一个添加进来的元素删除
				
			}
			else{
				if(val.subtract(res.get(size-1)).equals(res.get(size-2))){
					res.add(val);
					help(num, new ArrayList(res),i+1);
					res.remove(res.get(res.size()-1));//将最后一个添加进来的元素删除
				}
			}
			
		}
		
	}
	
	public static void main(String[] args){
		
		String str = "221474836472147483649";//2   2147483647   2147483649 
		System.out.println(new AdditiveNumber3().isAdditiveNumber(str));
		
	}
	
	
}
