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
        while(i<=len){//��i=lenʱ����0��ΪdummyԪ�أ����ã�ʹ��׼����ջ��ʱ��ǰ���Ԫ��ȫ������
        	int h=(i==len?0:heights[i]);
        	if(s.isEmpty()||heights[s.peek()]<=h){//����ǰԪ�ؽ�ջ
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
		System.out.println("�����"+res);
		
	}
}
