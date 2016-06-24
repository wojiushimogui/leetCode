package com.wrh.leetcode;

import java.util.Stack;
/*
 * 思路：借用一个Stack来保存节点
 * */

public class BSTIterator_v1 {

	private Stack<TreeNode> s;
    public BSTIterator_v1(TreeNode root) {
		s =new Stack<TreeNode> ();
    	pushLeft(root);
    }

	private void pushLeft(TreeNode root) {
		while(root!=null){
			s.push(root);
			root = root.left;
		}
	}


	/** @return whether we have a next smallest number */
    public boolean hasNext() {
        return !s.isEmpty();
    }

    /** @return the next smallest number */
    public int next() {
    	TreeNode t = s.pop();
    	pushLeft(t.right);
    	return t.val;
    }
}
