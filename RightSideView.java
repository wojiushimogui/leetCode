package com.wrh.leetcode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/*
 * ����ÿ������ұߵ��Ǹ��ڵ㼯
 * */

public class RightSideView {

    public List<Integer> rightSideView(TreeNode root) { 
    	List<Integer> res = new ArrayList<Integer> ();
    	
    	Queue<TreeNode> q1 = new LinkedList<TreeNode> ();
    	Queue<TreeNode> q2 = new LinkedList<TreeNode> ();
    	if(root==null){
    		return res;
    	}
    	q1.add(root);
    	while(!q1.isEmpty()){
    		
        	while(!q1.isEmpty()){
        		TreeNode t = q1.poll();
        		//����һ������һ���ڵ����������
        		if(q1.isEmpty()){
        			res.add(t.val);
        		}
        		//����һ��Ľڵ�������q2��
        		if(t.left!=null){
        			q2.add(t.left);
        		}
        		if(t.right!=null){
        			q2.add(t.right);
        		}       		
        		
        	}
        	//��q2�еĽڵ����뵽q1��
        	while(!q2.isEmpty()){
        		q1.add(q2.poll());
        	}
        
    	}
    	return res;

    }
}
