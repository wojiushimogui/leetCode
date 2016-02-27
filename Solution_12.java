package com.wrh.leetcode;

import java.util.LinkedList;
import java.util.Queue;

public class Solution_12 {
	//思路，还是一样借助两个队列来进行完成
	public void connect(TreeLinkNode root) {
        if(root==null){
        	return;
        }
        Queue<TreeLinkNode> q1=new LinkedList<TreeLinkNode>();
        Queue<TreeLinkNode> q2=new LinkedList<TreeLinkNode>();
        q1.add(root);
        root.next=null;
        while(!(q1.isEmpty()&&q2.isEmpty())){
        	while(!q1.isEmpty()){
        		TreeLinkNode node=q1.poll();
        		if(node.left!=null){
        			q2.add(node.left);
        		}
        		if(node.right!=null){
        			q2.add(node.right);
        		}
        	}
        	while(!q2.isEmpty()){
        		TreeLinkNode node=q2.poll();
        		if(q2.isEmpty()){
        			node.next=null;
        		}
        		else{
        			node.next=q2.peek();
        		}
        		q1.add(node);        		
        	}
        }
        
    }
}
