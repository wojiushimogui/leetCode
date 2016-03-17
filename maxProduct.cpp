#include<stdio.h>
#include<stdlib.h>

int max(int a,int b){
	return a>b?a:b;
}
/*
算法:最大产品值主要由两个因素决定：第一为 0元素，第二为负数的个数
当在遍历的过程中，遇到了 0元素，则采用以下的决策
1）如果此时的值为负数，则lowpoint逐渐向highpoint靠拢，使得当前值为正数
2）如果此时的值为正数，则抛弃掉此时的值，lowpoint跳过这个0元素的位置指向第一个非零值 
*/
int maxProduct(int* nums, int numsSize) {
    if(nums==NULL||numsSize<1){
    	return 0;
	}
	if(numsSize==1){
		return nums[0];
	}
	//用双指针来进行
	int lowpoint=0;
	int highpoint=0;
	int maxValue=INT_MIN;
	int curValue=1;
	while(highpoint<numsSize){
		if(nums[highpoint]==0&&curValue<0&&lowpoint<highpoint-1){
			for(;curValue<0&&lowpoint<highpoint-1;lowpoint++){//直到curValue为正 
				curValue/=nums[lowpoint];
				maxValue=max(maxValue,curValue);
			} 
									
		}
		else if(nums[highpoint]==0){
			maxValue=max(maxValue,0);//注意 
			highpoint++;
			lowpoint=highpoint;
			curValue=1;
		}
		else{
			curValue*=nums[highpoint++];
			maxValue=max(maxValue,curValue);
		}
	}
	for(;curValue<0&&lowpoint<numsSize-1;lowpoint++){//当curValue小于零时，则增大lowpoint 
		curValue/=nums[lowpoint];
		maxValue=max(maxValue,curValue);
	} 
	return maxValue;
}

int main(void){
	int len=7;
	int arr[len]={3,-2,-3,-3,1,3,0};
	int res=maxProduct(arr, len);
	printf("%d   ",res);
	
}
