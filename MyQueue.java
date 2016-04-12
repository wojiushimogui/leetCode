package com.wrh.leetcode;

import java.util.Stack;

public class MyQueue {
	/*
	 * Stack s1 和s2 用来模拟
	 * */
	Stack<Integer> s1=new Stack<Integer>();
	Stack<Integer> s2=new Stack<Integer>();
    public void push(int x) {
        s1.push(x);
    }
   
    public void pop() {
    	if(!s2.isEmpty()){
    		 s2.pop();
    	}
    	else if(s2.isEmpty()&&!s1.isEmpty()){
        	while(!s1.isEmpty()){
            	int temp=s1.pop();
            	s2.add(temp);
            }
        	s2.pop();
        }              
    }

    // Get the front element.
    public int peek() {
    	if(!s2.isEmpty()){
   		 	return s2.peek();
    	}
    	else if(s2.isEmpty()&&!s1.isEmpty()){
    		while(!s1.isEmpty()){
    			int temp=s1.pop();
    			s2.add(temp);
           }
    		return s2.peek();
       }
       return -1;//标识队列中没有元素
       
    }

    // Return whether the queue is empty.
    public boolean empty() {
        return s1.isEmpty()&&s2.isEmpty();
    }
}
