package com.wrh.leetcode;


public class MinStack {
	public Node head;
	public void push(int x) {
        if(head==null){
        	head=new Node(x,x,null);
        }
        else{
        	head=new Node(x,min(x,head.min),head);
        }
    }

    private int min(int a, int b) {
    	if(a<=b){
    		return a;
    	}  	
    	return b;
	}

	public void pop() {
        head=head.next;
    }

    public int top() {
        return head.val;
    }

    public int getMin() {
        return head.min;
    }
    class Node{
    	public int val;
    	public int min;
    	public Node next;
    	public Node(int val, int min, Node next) {
    		super();
    		this.val = val;
    		this.min = min;
    		this.next = next;
    	}
    	
    }
}

