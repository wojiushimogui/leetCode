package com.wrh.leetcode;

import java.util.ArrayList;
import java.util.List;

public class Solution_13 {
	/*
	 * 思路：根据层数来算出杨辉三角的值
	 * 杨辉三角的特性：第i层有i个元素，且每层的元素等于上一层的两个元素之后
	 * */
	public List<List<Integer>> generate(int numRows) {
		List<List<Integer>> res=new ArrayList<List<Integer>>();
        if(numRows<1){
        	return res;
        }
        List<Integer> temp=new ArrayList<Integer>();
        temp.add(new Integer(1));
        res.add(temp);
        for(int i=2;i<=numRows;i++){//从第二层开始
        	List<Integer> I_Res=new ArrayList<Integer>();
        	I_Res.add(1);//每层的第一个元素均是1
        	for(int j=1;j<i-1;j++){//算每层中间的元素，等于上一层的两个元素之和
        		int num=temp.get(j-1)+temp.get(j);//要注意的是j出界,为避免出界，因此将每层的最后一个元素分开加入
        		I_Res.add(num);
        	}
        	I_Res.add(1);//每层的最后一个元素也为1;
        	res.add(I_Res);
        	//I_Res.clear();//清零
        	temp=new ArrayList<Integer>(I_Res);//更新，供下一层的计算
        }
		return res;
    }
}
