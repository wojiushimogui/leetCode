package com.wrh.leetcode;

import java.util.ArrayList;
import java.util.List;

public class SumNumber {
	private List<List<Integer>> res=new ArrayList<List<Integer>>();//用来保存所有的路径
	public int sumNumbers(TreeNode root) {
        if(root==null){
        	return 0;
        }
        //第一步：找出所有的路径
        sumNumbersHelper(root,new ArrayList<Integer>());
        //求和
        return sumAllList(res);
    }

	private int sumAllList(List<List<Integer>> listList) {
		if(listList==null){
			return 0;
		}
		int sum=0;
		int listSum=0;
		for(List<Integer> temp:listList){
			listSum=0;//注意：要在这里初始化为零
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
		if(root.left==null&&root.right==null){//到达叶子节点，开始计算值			
        	res.add(list);
			return ;
        }
		else{
			sumNumbersHelper(root.left,new ArrayList<Integer>(list));
			sumNumbersHelper(root.right,new ArrayList<Integer>(list));
		}
	}
}
