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
	//函数功能：树节点中的value由start~end构成的二叉搜索树的所有结果
	private List<TreeNode> generateTrees(int start, int end) {
		List<TreeNode> res=new ArrayList<TreeNode>();
		if(end<start){
			res.add(null);
			return res;
		}
		for(int i=start;i<=end;i++){
			//产生以i为根节点，start~i-1构成左子树，i+1~end构成右子树
			List<TreeNode> leftSubTreeList=generateTrees(start,i-1);
			List<TreeNode> rightSubTreeList=generateTrees(i+1,end);
			//遍历并由根节点组合左子树和右子树构成最后的结果
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
