package com.wrh.leetcode;

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class PostorderTraversal {
	List<Integer> res=new ArrayList<Integer>();
	public List<Integer> postorderTraversal(TreeNode root) {
        if(root==null){
        	return res;
        }
        Stack<TreeNode> stack=new Stack<TreeNode>();
        stack.push(root);
        while(!stack.isEmpty()){
        	TreeNode node=stack.pop();
        	res.add(0, node.val);//插在第一个位置，使得满足“左右根”
        	if(node.left!=null){
        		stack.push(node.left);
        	}
        	if(node.right!=null){
        		stack.push(node.right);
        	}
        }
        return res;
    }
}
