package com.wrh.leetcode;

import java.util.Stack;

public class MaximalRectangle {
	
	public int maximalRectangle(char[][] matrix) {
        if(matrix==null||matrix.length<1||matrix[0].length<1){
        	return 0;
        }
        int height[]=new int[matrix[0].length];
        for(int i=0;i<matrix[0].length;i++){
        	if(matrix[0][i]=='1'){
        		height[i]=1;
        	}
        }
        int res=largestInLine(height);
        for(int row=1;row<matrix.length;row++){
        	for(int col=0;col<matrix[0].length;col++){
        		if(matrix[row][col]=='1'){
        			height[col]++;
        		}
        		else{
        			height[col]=0;
        		}
        	}
        	res=Math.max(res,largestInLine(height));
        }
		return res;
    }

	public int largestInLine(int[] height) {
	    if(height == null || height.length == 0) return 0;
	    int len = height.length;
	    Stack<Integer> s = new Stack<Integer>();
	    int maxArea = 0;
	    for(int i = 0; i <= len; i++){
	        int h = (i == len ? 0 : height[i]);
	        if(s.isEmpty() || h >= height[s.peek()]){
	            s.push(i);
	        }else{
	            int tp = s.pop();
	            maxArea = Math.max(maxArea, height[tp] * (s.isEmpty() ? i : i - 1 - s.peek()));
	            i--;
	        }
	    }
	    return maxArea;
	}
}
