package com.wrh.leetcode;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class PreorderTraversal {
	List<Integer> res=new ArrayList<Integer>();
	public List<Integer> preorderTraversal(TreeNode root) {
        if(root==null){
        	return res;
        }
        Stack<TreeNode> stack=new Stack<TreeNode>();
        stack.push(root);
        while(!stack.isEmpty()){
        	TreeNode node=stack.pop();
        	res.add(node.val);
        	if(node.right!=null){
        		stack.push(node.right);
        	}
        	if(node.left!=null){
        		stack.push(node.left);
        	}
        }
		return res;
    }
}
