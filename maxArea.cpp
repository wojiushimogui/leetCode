
//寻找面积最大，容器的体积由两个高度中较低的高度和圆底的半径决定：area=min(height[i],height[j])*(j-i)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int min(int a,int b){
	return a<=b?a:b;
}
int maxArea(int* height, int heightSize) {
    if(height==NULL||heightSize<1){
    	return 0;
	} 
	int max=0;
	for(int i=0;i<heightSize;i++){
		for(int j=i+1;j<heightSize;j++){
			int area=min(height[i],height[j])*(j-i);
			if(area>max){
				max=area;
			}
		}
	}
	return max;
}

/*
The idea is that a container to hold water can only be formed
 by two two heights with the lowest height as the height of the container. 
 So, if we start from two numbers farthest apart in length (i.e. first and last element) 
 then we have maximum width rectangle.
  Now, we can move to shorter height only to left or right to maximize the total area.
*/

public class Solution {
    public int maxArea(int[] height) {
        int len = height.length, low = 0, high = len -1 ;  
        int maxArea = 0;  
        while (low < high) {  
         maxArea = Math.max(maxArea, (high - low) * Math.min(height[low], height[high]));  
         if (height[low] < height[high]) {  
           low++;  
         } else {  
           high--;  
         }  
        }  
        return maxArea;  
    }
}
