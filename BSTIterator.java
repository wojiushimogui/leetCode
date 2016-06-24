package com.wrh.leetcode;

import java.util.ArrayList;
import java.util.List;
/*
 * 思路：将root节点保存按照从小到大的顺序起来
 * */

public class BSTIterator {

	private List<TreeNode> list = new ArrayList<TreeNode> ();
	private int totalNodeNum;
	private int num;
    public BSTIterator(TreeNode root) {
        saveNodeToList(root);
        totalNodeNum = list.size();
        num = 0;
    }

    private void saveNodeToList(TreeNode root) {
    	if(root==null){
    		return ;
    	}
    	if(root.left!=null){
    		saveNodeToList(root.left);
    	}
    	list.add(root);
    	if(root.right!=null){
    		saveNodeToList(root.right);
    	}
	}

	/** @return whether we have a next smallest number */
    public boolean hasNext() {
        return (num<totalNodeNum);
    }

    /** @return the next smallest number */
    public int next() {
    	int val = list.get(num).val;
    	num ++;
        return val;
    }
}
