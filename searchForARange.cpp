/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

#include<stdio.h>
#include<stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int binarySearch(int *nums,int begin,int end,int target,bool flag){
	if(nums==NULL||begin>end){
		return -1;
	} 
	int mid=begin+end>>1;
	int val=nums[mid];
	if(val==target){
		//根据传送过来的flag来判断是否是寻找的是起点还是终点的下标。 
		int index=flag?(binarySearch(nums,begin,mid-1,target,flag)) :(binarySearch(nums,mid+1,end,target,flag));
		return index==-1?mid:index;
	}
	else if(val>target){
		end=mid-1;
		return binarySearch(nums,begin,end,target,flag);
	}
	else{
		begin=mid+1;
	    return 	binarySearch(nums,begin,end,target,flag);
	}
		
	return -1;//没找到返回 -1 
		
} 
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
	//先构造没有找到时要返回的数组result 
	int *result=(int *)malloc(2*sizeof(int));
	if(result==NULL){
		exit(EXIT_FAILURE);
	}
	result[0]=-1;
	result[1]=-1; 
    if(nums==NULL||numsSize<1){
    	*returnSize=2;
    	return result;
	}
	int begin=0;
	int end=numsSize-1;
	//应用两次二分查找来寻找目标数的起点和终点。 
	int startIndex=binarySearch(nums,begin,end,target,true);
	int endIndex=binarySearch(nums,begin,end,target,false);
	
	if(startIndex==-1&&endIndex==-1){//没有找到 
		*returnSize=2;
		return result;
	}
	*returnSize=(endIndex-startIndex)+1;
	if(*returnSize<2){
		*returnSize=2;
	}
	result[0]=startIndex;
	result[1]=endIndex;		
	return result;
}


int main(void){
	int k;
	int target;
	while(scanf("%d  %d",&k,&target)!=EOF&&k>0){
		int *arr=(int *)malloc(k*sizeof(int));
		if(arr==NULL){
			exit(EXIT_FAILURE);
		}
		for(int i=0;i<k;i++){//输入一个排序的数组 
			scanf("%d",arr+i);
		}
		int returnSize=0;
		int *result=searchRange(arr, k, target, &returnSize);
		for(int i=0;i<returnSize;i++){
			printf("%d   ",result[i]);
		}
		printf("\n");
	}
	return 0;
}
