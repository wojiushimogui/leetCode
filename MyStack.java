package com.wrh.leetcode;

import java.util.LinkedList;
import java.util.Queue;

/*
 * ��������������ʵ��ջ
 * */
public class MyStack {
	Queue<Integer> q1=new LinkedList<Integer>();
	Queue<Integer> q2=new LinkedList<Integer>();
	// Push element x onto stack.
    public void push(int x) {
        q1.add(x);
    }

    // Removes the element on top of the stack.
    public void pop() {
        if(q1.isEmpty()){
        	return;
        }
        else{
        	int len=q1.size();
        	for(int i=0;i<len-1;i++){
        		q2.add(q1.poll());
        	}
        	q1.poll();//���һ��Ԫ�ز�Ҫ��
        	for(int i=0;i<len-1;i++){
        		q1.add(q2.poll());
        	}
        }
    }

    // Get the top element.
    public int top() {
    	if(q1.isEmpty()){
        	return -1;
        }
        else{
        	int len=q1.size();
        	for(int i=0;i<len-1;i++){
        		q2.add(q1.poll());
        	}
        	int res=q1.poll();//�������һ��Ԫ�ء�
        	q2.add(res);
        	for(int i=0;i<len;i++){
        		q1.add(q2.poll());
        	}
        	return res;
        }
    }

    // Return whether the stack is empty.
    public boolean empty() {
        
    	return q1.isEmpty();
    }
}
