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
			if(sum==root.val){//符合条件的则将其加入
				res.add(arrayList);
			}
		}
		//如果此节点不是叶子节点，则
		pathSumHelper(new ArrayList<Integer>(arrayList),root.left,sum-root.val);
		pathSumHelper(new ArrayList<Integer>(arrayList),root.right,sum-root.val);	
	}
}
