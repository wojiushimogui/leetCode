package com.wrh.leetcode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Rob {
	/*
	 * ����������������ɰ�����ȡ�����ڵ㡣
	 * */
	public int rob(TreeNode root) {
		if(root==null){
			return 0;
		}
		if(root.left==null&&root.right==null){//ֻ��һ��
			return root.val;
		}
        Queue<TreeNode> q1=new LinkedList<TreeNode>();
        Queue<TreeNode> q2=new LinkedList<TreeNode>();
        q1.add(root);
        List<Integer> res=new ArrayList<Integer>();
//        res.add(root.val);
        while(!q1.isEmpty()){
        	int maxValue=0;
        	while(!q1.isEmpty()){
            	TreeNode node=q1.poll();
            	maxValue+=node.val;
            	if(node.left!=null){
            		q2.add(node.left);
            	}
            	if(node.right!=null){
            		q2.add(node.right);
            	}
            }
        	//��ʼ����һ��ڵ�ĺ� ������ĵ�����2��͵�����3����ܲ��������ֵ��
        	int len=res.size();
        	if(len<2){//��һ��͵ڶ���Ľڵ��ֱ�ӽ��뼴��
        		res.add(maxValue);
        	}
        	else if(len==2){
        		maxValue+=res.get(len-2);
        		res.add(maxValue);
        	}
        	else if(len>=3){
        		maxValue+=Math.max(res.get(len-2),res.get(len-3));
        		res.add(maxValue);
        	}
//        	q1.addAll(q2);
//        	q2.clear();
        	while(!q2.isEmpty()){
            	q1.add(q2.poll());
            }
        }
        
		return Math.max(res.get(res.size()-1), res.get(res.size()-2));
    }
}
