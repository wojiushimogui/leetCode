package com.wrh.leetcode;

import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Solution_10 {

	public static void main(String[] args) {
		
		
	}
	public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        
		return  zigzagLevelOrderHelper(root);
    }
	//˼·�����ǽ�����������������
	private List<List<Integer>> zigzagLevelOrderHelper(TreeNode root) {
		List<List<Integer>> res=new ArrayList<List<Integer>>();
		if(root==null){
			return res;
		}
		Queue<TreeNode> q1=new LinkedList<TreeNode>();
		Queue<TreeNode> q2=new LinkedList<TreeNode>();
		//�����ڵ������
		q1.add(root);
		//�����ڵ��ֵ�����ڽ����
		List<Integer> firstRes=new ArrayList<Integer>();
		firstRes.add(root.val);
		res.add(firstRes);
		int leverIndex=2;//���潫�ӵڶ��㿪ʼ
		while(!(q1.isEmpty()&&q2.isEmpty())){
			while(!q1.isEmpty()){
				//��q1�ж���Ԫ�س�ջ
				TreeNode node=q1.poll();
				if(node.left!=null){
					q2.add(node.left);
				}
				if(node.right!=null){
					q2.add(node.right);
				}
			}
			//��q2�е�Ԫ��ת��q1��
			List<Integer> leverNodeValue=new ArrayList<Integer>();
			while(!q2.isEmpty()){
				TreeNode tempNode=q2.poll();
				leverNodeValue.add(tempNode.val);
				q1.add(tempNode);
			}
			if(leverIndex%2==0){//��Ҫ��ת
				Collections.reverse(leverNodeValue);
			}
			if(!leverNodeValue.isEmpty()){//ע��Ҫ�ж�
				res.add(leverNodeValue);
			}
			leverIndex++;
		
		}
		return res;
	}

}
