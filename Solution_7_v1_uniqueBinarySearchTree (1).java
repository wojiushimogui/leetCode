package com.wrh.leetcode;

import java.util.ArrayList;
import java.util.List;

public class Solution_7_v1 {
	public List<TreeNode> generateTrees(int n) {
        if(n<1){
        	return null;
        }
		return generateTrees(1,n);	
    }
	//�������ܣ����ڵ��е�value��start~end���ɵĶ��������������н��
	private List<TreeNode> generateTrees(int start, int end) {
		List<TreeNode> res=new ArrayList<TreeNode>();
		if(end<start){
			res.add(null);
			return res;
		}
		for(int i=start;i<=end;i++){
			//������iΪ���ڵ㣬start~i-1������������i+1~end����������
			List<TreeNode> leftSubTreeList=generateTrees(start,i-1);
			List<TreeNode> rightSubTreeList=generateTrees(i+1,end);
			//�������ɸ��ڵ�������������������������Ľ��
			for(TreeNode leftSubTree:leftSubTreeList){
				for(TreeNode rightSubTree:rightSubTreeList){
					TreeNode root=new TreeNode(i);
					root.left=leftSubTree;
					root.right=rightSubTree;
					res.add(root);
				}
			}
		}
		return res;
	}
}
