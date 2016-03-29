package com.wrh.leetcode;

public class LargestRectangleArea {
	public int largestRectangleArea(int[] heights) {
        if(heights==null||heights.length<1){
        	return 0;
        }
        int len=heights.length;
        int largestArea=0;
        for(int i=0;i<len;i++){
        	int h=heights[i];
        	int area=0;
        	for(int j=i+1;j<len;j++){
        		if(heights[j]<h){//使得h一直是最小的
        			h=heights[j];
        		}
        		area=(j-i+1)*h;
        		largestArea=largestArea>area?largestArea:area;//更新
        	}
        }		
		return largestArea;
    }
}
