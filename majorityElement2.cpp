#include<stdio.h>
#include<stdlib.h>
/*
Given an integer array of size n,
 find all elements that appear more than ? n/3 ? times.
The algorithm should run in linear time and in O(1) space.
*/
int *res=NULL;
int indexRes=0; 

void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
} 
void majorityElementHelper(int *nums,int left,int right,int len){
	if(nums==NULL||right<left){
		return;
	}
	//选取mid位置的值作为pivot值 
	int mid=(left+right)/2;
	int val=nums[mid];
	
	int m=left;//用来指示 调整后的结果中，m左边的值都是小于val的。 
	int n=left;//用来指示  调整后的结果中，m~n中的值都是等于val的。n~right都是大于val的 
	swap(nums+left,nums+mid);//将pivot放入nums第一个位置 
	int i=left+1;
	while(i<=right){
		if(nums[i]<val){
			swap(&nums[m++],&nums[i]);//将小于val的值放入m下标的左边 
			swap(&nums[++n],&nums[i++]);//使得n总是指向最右边的等于val的下标 
		}
		else if(nums[i]==val){
			swap(&nums[++n],&nums[i++]);
		}
		else{
			i++;
		}
	}
	if(n-m+1>=len){//符合条件 
		res[indexRes++]=nums[n];
	} 
	if(m-left>=len){//小于val的长度大于len，因此可能有解 
		majorityElementHelper(nums,left,m-1,len);
	}
	if(right-n>=len){//大于val的长度大于len，因此可能有解 
		majorityElementHelper(nums,n+1,right,len);
	}
}

int* majorityElement(int* nums, int numsSize, int* returnSize) {
    if(nums==NULL||numsSize<1){
    	*returnSize=0;
    	return NULL;
	}
	int maxLen=3;//最多只有三个解 
	res=(int *)malloc(maxLen*sizeof(int));
	if(res==NULL){
		exit(EXIT_FAILURE);
	}
	indexRes=0;	
	majorityElementHelper(nums,0,numsSize-1,(numsSize/3)+1);
	*returnSize=indexRes;
	return res;	
}
