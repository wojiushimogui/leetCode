package com.wrh.leetcode;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/*
 * 看到每层的最右边的那个节点集
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
        		//将这一层的最后一个节点加入结果集中
        		if(q1.isEmpty()){
        			res.add(t.val);
        		}
        		//将下一层的节点放入队列q2中
        		if(t.left!=null){
        			q2.add(t.left);
        		}
        		if(t.right!=null){
        			q2.add(t.right);
        		}       		
        		
        	}
        	//将q2中的节点移入到q1中
        	while(!q2.isEmpty()){
        		q1.add(q2.poll());
        	}
        
    	}
    	return res;

    }
}
