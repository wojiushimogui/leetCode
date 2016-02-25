package com.wrh.leetcode;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class Solution_9 {

	public static void main(String[] args) {
		TreeNode node=new TreeNode(3);
		new Solution_9().levelOrderBottom(node);
	}
	/*
	 * 思路：借助于两个队列来完成即可
	 * */
	public List<List<Integer>> levelOrderBottom(TreeNode root) {
		//先按层从左到右的获取节点值
		Stack<List<Integer>> leverOrderUptoBottomRes=leverOrderBottomHelper(root);
		//将leverOrderUptoBottomRes翻转即可
		return reversalResult(leverOrderUptoBottomRes);
	        
	}
	private List<List<Integer>> reversalResult(
			Stack<List<Integer>> leverOrderUptoBottomRes) {
		List<List<Integer>> temp=new ArrayList<List<Integer>>();
		while(!leverOrderUptoBottomRes.isEmpty()){
			List<Integer> list=leverOrderUptoBottomRes.pop();
			if(!list.isEmpty()){
				temp.add(list);
			}
			
		}
		return temp;
	}
	private Stack<List<Integer>> leverOrderBottomHelper(TreeNode root) {
		Stack<List<Integer>> res=new Stack<List<Integer>>();
		if(root==null){
			return res;
		}
		ArrayDeque<TreeNode> q1=new ArrayDeque<TreeNode>();
		ArrayDeque<TreeNode> q2=new ArrayDeque<TreeNode>();
		//将头结点元素放入q1队列中
		q1.add(root);
		List<Integer> firstNodeValue=new ArrayList<Integer>();
		firstNodeValue.add(root.val);
		res.push(firstNodeValue);//先将第一个结点保存在结果中
		while(!(q1.isEmpty()&&q2.isEmpty())){
			while(!q1.isEmpty()){
				TreeNode node=q1.poll();//获取队首元素
				if(node.left!=null){
					q2.add(node.left);
				}
				if(node.right!=null){
					q2.add(node.right);
				}
			}
			List<Integer> leverRes=new ArrayList<Integer>();
			while(!q2.isEmpty()){
				TreeNode tempNode=q2.poll();
				leverRes.add(tempNode.val);
				q1.add(tempNode);
			}
			res.push(leverRes);
		}		
		return res;
	}

}
