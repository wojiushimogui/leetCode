package com.wrh.leetcode;

import java.util.ArrayList;
import java.util.List;

public class Solution_11 {
	private List<List<Integer>> res=new ArrayList<List<Integer>>();
	public List<List<Integer>> pathSum(TreeNode root, int sum) {
		pathSumHelper(new ArrayList<Integer>(),root,sum);
		return res;
	}
	private void pathSumHelper(ArrayList<Integer> arrayList, TreeNode root,
			int sum) {
		if(root==null){
			return ;
		}
		arrayList.add(root.val);
		if(root.left==null&&root.right==null){
			if(sum==root.val){//�����������������
				res.add(arrayList);
			}
		}
		//����˽ڵ㲻��Ҷ�ӽڵ㣬��
		pathSumHelper(new ArrayList<Integer>(arrayList),root.left,sum-root.val);
		pathSumHelper(new ArrayList<Integer>(arrayList),root.right,sum-root.val);	
	}
}
