package com.wrh.leetcode;

import java.util.ArrayList;
import java.util.List;

public class SumNumber {
	private List<List<Integer>> res=new ArrayList<List<Integer>>();//�����������е�·��
	public int sumNumbers(TreeNode root) {
        if(root==null){
        	return 0;
        }
        //��һ�����ҳ����е�·��
        sumNumbersHelper(root,new ArrayList<Integer>());
        //���
        return sumAllList(res);
    }

	private int sumAllList(List<List<Integer>> listList) {
		if(listList==null){
			return 0;
		}
		int sum=0;
		int listSum=0;
		for(List<Integer> temp:listList){
			listSum=0;//ע�⣺Ҫ�������ʼ��Ϊ��
			for(Integer num:temp){
				listSum=listSum*10+num;
			}
			sum+=listSum;
		}
		return sum;
	}

	private void sumNumbersHelper(TreeNode root,List<Integer> list) {
		if(root==null){
			return;
		}
		list.add(root.val);
		if(root.left==null&&root.right==null){//����Ҷ�ӽڵ㣬��ʼ����ֵ			
        	res.add(list);
			return ;
        }
		else{
			sumNumbersHelper(root.left,new ArrayList<Integer>(list));
			sumNumbersHelper(root.right,new ArrayList<Integer>(list));
		}
	}
}
