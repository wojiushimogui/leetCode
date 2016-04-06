#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
/*
�������ܣ�
��start��Ԫ�ر������ܲ��������ֵ */
int *result;
int robHelper(int* nums, int numsSize,int start){
	if(nums==NULL||numsSize<1||numsSize<=start){
    	return 0;
	}
	if(result[start]!=-1){
		return result[start];
	}
	int res1=robHelper(nums,numsSize,start+2);
	int res2=robHelper(nums,numsSize,start+3);
	int res=nums[start]+max(res1,res2)
	result[start]=res;
	return ;
}

int rob(int* nums, int numsSize) {  
	if(nums==NULL||numsSize<1){
		return 0;
	}
	result=(int *)malloc(numsSize*sizeof(int));
	if(result==NULL){
		exit(EXIT_FAILURE);
	} 
	memset(result,-1,numsSize*sizeof(int));//��ʼ��Ϊ-1
	int fristElementMax=robHelper(nums,numsSize,0);//��һ��Ԫ�ر�������������ֵ 
	int secondElementMax=robHelper(nums,numsSize,1);//�ڶ���Ԫ�ر�������ܲ��������ֵ 
	return fristElementMax>secondElementMax?fristElementMax:secondElementMax;
}
