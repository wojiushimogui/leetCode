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
	 * ˼·��������������������ɼ���
	 * */
	public List<List<Integer>> levelOrderBottom(TreeNode root) {
		//�Ȱ�������ҵĻ�ȡ�ڵ�ֵ
		Stack<List<Integer>> leverOrderUptoBottomRes=leverOrderBottomHelper(root);
		//��leverOrderUptoBottomRes��ת����
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
		//��ͷ���Ԫ�ط���q1������
		q1.add(root);
		List<Integer> firstNodeValue=new ArrayList<Integer>();
		firstNodeValue.add(root.val);
		res.push(firstNodeValue);//�Ƚ���һ����㱣���ڽ����
		while(!(q1.isEmpty()&&q2.isEmpty())){
			while(!q1.isEmpty()){
				TreeNode node=q1.poll();//��ȡ����Ԫ��
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
