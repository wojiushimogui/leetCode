
/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
 /*
 方法一：暴力搜索法，利用三个for循环进行遍历，时间复杂度为O（n^3） 
 */
 
int cmp(const void *a,const void *b){
	return (*((int *)a))-*((int *)b);
}
int** threeSum(int* nums, int numsSize, int* returnSize) {
    if(nums==NULL||numsSize<3){
    	return NULL;
	}
	int nn=(numsSize)*(numsSize-1)*(numsSize-2)/6;
	int **result=(int **)malloc((nn)*sizeof(int *));
	
	int index=0;
	for(int i=0;i<numsSize-2;i++){
		for(int j=i+1;j<numsSize-1;j++){
			for(int k=j+1;k<numsSize;k++){
				if(nums[i]+nums[j]+nums[k]==0){
					//记录下来
					result[index]=(int *)malloc(3*sizeof(int));
					if(result[index]==NULL){
						exit(EXIT_FAILURE);
					} 
					//将这三个数进行排序
					result[index][0]=nums[i];
					result[index][1]=nums[j];
					result[index][2]=nums[k];
					qsort(result[index],3,sizeof(result[index][0]),cmp);
					//检查下result有没有重复的
					for(int i1=0;i1<index;i1++) {
						if(result[i1][0]==result[index][0]&&result[i1][1]==result[index][1]&&result[i1][2]==result[index][2]){
							free(result[index]);
							result[index]=NULL;
							index--;
						}
					}
					index++; 
				}
			}
		}
	}
	*returnSize=index;
	return result;
}


int main(void){
	int n;
	while(scanf("%d",&n)!=EOF&&n>=3){
		int *arr=(int *)malloc(n*sizeof(int ));
		if(arr==NULL){
			exit(EXIT_FAILURE);
		}
		for(int i=0;i<n;i++){
			scanf("%d",arr+i);
		}
		int returnSize=0;
		int **result=threeSum(arr,n,&returnSize);
		for(int i=0;i<returnSize;i++){
			int *temp=(result[i]);
			for(int j=0;j<3;j++){
				printf("%d   ",temp[j]);
			}
			printf("\n");
		}
		
		for(int i=0;i<returnSize;i++){
			free(result[i]);
			result[i]=NULL;
		}
		
	}
	return 0;
}
