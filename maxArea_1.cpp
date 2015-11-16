#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
思路：
一个容器装水只能由两个高度中最低的高度作为容器的高度。
如果我们从两个数相隔最远的长度(即第一个和最后一个元素),那么我们最大宽度矩形。
现在,我们可以搬到更短的跨度但是高度只到左或右最大化总面积。 
现在，我们可以移动高度较小的那个高度（即较少宽度，但是高度可能增加，这样总面积可能也会增加），来获取最大的总面积 
*/

int min(int a,int b){
	return a<=b?a:b;
}
int maxArea(int* height, int heightSize) {
    if(height==NULL||heightSize<1){
    	return 0;
	} 
	int max=0;
	int begin=0;
	int end=heightSize-1;
	while(begin<end){
		int area=min(height[begin],height[end])*(end-begin);
		if(area>max){
				max=area;
		}
		if(height[begin]>height[end]){
			end--;
		}
		else if(height[begin]<=height[end]){
			begin++;
		}
	} 
	
	return max;
}

int main(void){
	int n;
	while(scanf("%d",&n)!=EOF&&n>0){
		int *arr=(int *)malloc(n*sizeof(int));
		if(arr==NULL){
			exit(EXIT_FAILURE); 
		}
		for(int i=0;i<n;i++){
			scanf("%d",arr+i);
		}
		int result=maxArea(arr,n);
		printf("%d\n",result);
	}
	return 0;
} 
