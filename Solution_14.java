package com.wrh.leetcode;

import java.util.ArrayList;
import java.util.List;

public class Solution_14 {
	 public List<Integer> getRow(int rowIndex) {
	        if(rowIndex<0){
	            return  new ArrayList<Integer>();
	        }
	        List<Integer> result=generate( rowIndex+1);//rowIndex�Ǵ��㿪ʼ��
	        return result;
	    }
	//@param rowIndex�Ǵ�1��ʼ
	private List<Integer> generate(int rowIndex) {
		List<Integer> curFloor=new ArrayList<Integer>();
		List<Integer> nextFloor=new ArrayList<Integer>();
		curFloor.add(1);
		if(rowIndex==1){//��һ�е����ó�������
			return curFloor;
		}
		for(int i=2;i<=rowIndex;i++){
			nextFloor.clear();//����
			nextFloor.add(1);
			for(int j=1;j<i-1;j++){
				int num=curFloor.get(j-1)+curFloor.get(j);
				nextFloor.add(num);
			}
			nextFloor.add(1);
			curFloor.clear();
			curFloor=new ArrayList<Integer>(nextFloor);
		}
		return nextFloor;
	}
}
