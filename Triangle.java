package com.wrh.leetcode;

import java.util.List;

public class Triangle {
	 /*
	  * ˼·��Ѱ��ÿ���е���Сֵ��Ȼ���ۼ���ͼ���
	  * */
	 public int minimumTotal(List<List<Integer>> triangle) {
	     int size=triangle.size();
	     int res[]=new int[size+1];
	     for(int i=size-1;i>=0;i--){//����DP�������Ͻ���
	    	 List<Integer> temp=triangle.get(i);
	    	 for(int j=0;j<temp.size();j++){
	    		 //��������i���е�j��Ԫ������С��·����ʱ����ֻ����min(res[j],res[j+1])+temp.get(j)
	    		 res[j]=Math.min(res[j], res[j+1])+temp.get(j);
	    	 }
	     }
		 return res[0];
	 }

	
}
