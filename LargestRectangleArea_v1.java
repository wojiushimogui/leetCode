package com.wrh.leetcode;

import java.util.Stack;

public class LargestRectangleArea_v1 {
	public int largestRectangleArea(int[] heights) {
        if(heights==null||heights.length<1){
        	return 0;
        }
       
        int len=heights.length;
        int i=0;
        Stack<Integer> s=new Stack<Integer>();
        int largestArea=0;
        while(i<=len){//当i=len时，用0作为dummy元素，作用：使它准备进栈的时候，前面的元素全部弹出
        	int h=(i==len?0:heights[i]);
        	if(s.isEmpty()||heights[s.peek()]<=h){//将当前元素进栈
        		s.push(i);   
        		i++;
        	}
        	else{
        		int top=s.pop();
        		int tempRes=heights[top]*(s.isEmpty()?i:i-s.peek()-1);
        		largestArea=max(largestArea,tempRes);
        	}
        }      
        return largestArea;
    }

	private int max(int a, int b) {		
		return a>b?a:b;
	}
	public static void main(String []args){
		int h[]=new int[1];
		h[0]=1;
		LargestRectangleArea_v1 l=new LargestRectangleArea_v1();
		int res=l.largestRectangleArea(h);
		System.out.println("结果："+res);
		
	}
}
