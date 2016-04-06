#include<stdio.h>
#include<stdlib.h>
#include<string.h>  
int max(int a,int b){
    return a>b?a:b;
}
int maxInArr(int *nums,int numsSize){
    if(nums==NULL||numsSize<1){
        return 0;
    }
    int maxValue=0;
    for(int i=0;i<numsSize;i++){
        if(maxValue<nums[i]){
            maxValue=nums[i];
        }
    }
    return maxValue;
}
int robHelper(int *nums,int numsSize){
    if(nums==NULL||numsSize<1){
		return 0;
	}
	int *result=(int *)malloc(numsSize*sizeof(int));
	if(result==NULL){
		exit(EXIT_FAILURE);
	} 
	memset(result,0,numsSize*sizeof(int));//初始化为0	
	for(int i=numsSize-1;i>=0;i--){
		if(i==numsSize-1){
			result[numsSize-1]=nums[numsSize-1];
		}
		else if(i==numsSize-2){
			result[numsSize-2]=nums[numsSize-2];
		}
		else if(i==numsSize-3){
			result[i]=nums[i]+nums[i+2];
		}
		else {
			result[i]=nums[i]+max(result[i+2],result[i+3]);
		}
	}
	return max(result[0],result[1]);
}

int rob(int* nums, int numsSize) {  
	if(nums==NULL||numsSize<1){
		return 0;
	}
	if(numsSize<=3){
	    return maxInArr(nums,numsSize);
	}
	int res1=robHelper(nums,numsSize-1);//第一个元素可能参与产生最大值 
	int res2=robHelper(nums+1,numsSize-1);//最后一个元素可能参与产生最大值 
	return max(res1,res2); 
}
