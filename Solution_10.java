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
	//思路：还是借助两个队列来进行
	private List<List<Integer>> zigzagLevelOrderHelper(TreeNode root) {
		List<List<Integer>> res=new ArrayList<List<Integer>>();
		if(root==null){
			return res;
		}
		Queue<TreeNode> q1=new LinkedList<TreeNode>();
		Queue<TreeNode> q2=new LinkedList<TreeNode>();
		//将根节点入队列
		q1.add(root);
		//将根节点的值保存在结果中
		List<Integer> firstRes=new ArrayList<Integer>();
		firstRes.add(root.val);
		res.add(firstRes);
		int leverIndex=2;//下面将从第二层开始
		while(!(q1.isEmpty()&&q2.isEmpty())){
			while(!q1.isEmpty()){
				//将q1中队首元素出栈
				TreeNode node=q1.poll();
				if(node.left!=null){
					q2.add(node.left);
				}
				if(node.right!=null){
					q2.add(node.right);
				}
			}
			//将q2中的元素转到q1中
			List<Integer> leverNodeValue=new ArrayList<Integer>();
			while(!q2.isEmpty()){
				TreeNode tempNode=q2.poll();
				leverNodeValue.add(tempNode.val);
				q1.add(tempNode);
			}
			if(leverIndex%2==0){//需要翻转
				Collections.reverse(leverNodeValue);
			}
			if(!leverNodeValue.isEmpty()){//注意要判断
				res.add(leverNodeValue);
			}
			leverIndex++;
		
		}
		return res;
	}

}
