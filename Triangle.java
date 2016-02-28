package com.wrh.leetcode;

import java.util.List;

public class Triangle {
	 /*
	  * 思路：寻找每行中的最小值，然后累加求和即可
	  * */
	 public int minimumTotal(List<List<Integer>> triangle) {
	     int size=triangle.size();
	     int res[]=new int[size+1];
	     for(int i=size-1;i>=0;i--){//利用DP从下往上进行
	    	 List<Integer> temp=triangle.get(i);
	    	 for(int j=0;j<temp.size();j++){
	    		 //当决定第i层中第j个元素是最小和路径中时，则只能在min(res[j],res[j+1])+temp.get(j)
	    		 res[j]=Math.min(res[j], res[j+1])+temp.get(j);
	    	 }
	     }
		 return res[0];
	 }

	
}
