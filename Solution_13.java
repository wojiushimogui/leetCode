package com.wrh.leetcode;

import java.util.ArrayList;
import java.util.List;

public class Solution_13 {
	/*
	 * ˼·�����ݲ��������������ǵ�ֵ
	 * ������ǵ����ԣ���i����i��Ԫ�أ���ÿ���Ԫ�ص�����һ�������Ԫ��֮��
	 * */
	public List<List<Integer>> generate(int numRows) {
		List<List<Integer>> res=new ArrayList<List<Integer>>();
        if(numRows<1){
        	return res;
        }
        List<Integer> temp=new ArrayList<Integer>();
        temp.add(new Integer(1));
        res.add(temp);
        for(int i=2;i<=numRows;i++){//�ӵڶ��㿪ʼ
        	List<Integer> I_Res=new ArrayList<Integer>();
        	I_Res.add(1);//ÿ��ĵ�һ��Ԫ�ؾ���1
        	for(int j=1;j<i-1;j++){//��ÿ���м��Ԫ�أ�������һ�������Ԫ��֮��
        		int num=temp.get(j-1)+temp.get(j);//Ҫע�����j����,Ϊ������磬��˽�ÿ������һ��Ԫ�طֿ�����
        		I_Res.add(num);
        	}
        	I_Res.add(1);//ÿ������һ��Ԫ��ҲΪ1;
        	res.add(I_Res);
        	//I_Res.clear();//����
        	temp=new ArrayList<Integer>(I_Res);//���£�����һ��ļ���
        }
		return res;
    }
}
