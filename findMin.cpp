#include<stdio.h>
#include<stdlib.h>

//函数功能：将数组转换为十进制数 
int arrayToNum(int* nums, int numsSize){
	if(nums==NULL||numsSize<1){
    	return 0;
	}
	int res=0;
	for(int i=0;i<numsSize;i++){
		res=res*10+nums[i];
	}
	return res;
}
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
//函数功能：将数组进行逆序 
void reverse(int* nums, int numsSize){
	if(nums==NULL||numsSize<1){
    	return;
	}
	int begin=0;
	int end=numsSize-1;
	while(begin<end){
		swap(&nums[begin],&nums[end]);
		begin++;
		end--;
	} 
} 
int findMin(int* nums, int numsSize) {
    if(nums==NULL||numsSize<1){
    	return 0;
	}
	//在所有的结果中寻找最小 
	//借组一个中间数组
	int *temp=(int *)malloc(numsSize*sizeof(int));
	if(temp==NULL){
		exit(EXIT_FAILURE);
	} 
	int minRes=arrayToNum(nums,numsSize);
	for(int i=0;i<numsSize;i++){		
		for(int j=0;j<numsSize;j++){
			temp[j]=nums[j];
		}
		//将数组向右边旋转i位:即将数组前面的（numsSize-i）个元素逆序，后面的i个元素逆序，最后整体逆序即可完成。 
		reverse(temp,numsSize-i);
		reverse(temp+numsSize-i,i);
		reverse(temp,numsSize); 
		int res=arrayToNum(temp,numsSize);
		if(res<minRes){
			minRes=res;
		}
	}
	return minRes;
}
