
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
思路：
第一步：从后开始遍历，找到第一个相邻两个元素升序的位置pos.
第二步：如果没有找到pos，则说明是最大的一个排列，将其反序即可。如果找到了pos，
则从后开始遍历，找到第一个大于nums[pos]值的位置k,然后交换nums[pos]与nums[k] 的位置
第三步：将pos之后的所有元素进行一个排序（升序）即可 
*/

int cmp(const void * a,const void *b){
	return (*((int *)a))-(*((int *)b));
}
void nextPermutation(int* nums, int numsSize) {
    if(nums==NULL||numsSize<2){
        return;
    }
    int pos=-1; 
    //第一步：从后开始遍历，找到第一个相邻两个元素升序的位置pos. 
    for(int i=numsSize-1;i>0;i--){
        if(nums[i]>nums[i-1]){
        	pos=i-1;
        	break;
		}
    }
    if(pos==-1){//说明此数时最大的一个排列，则将其排序即可
		qsort(nums,numsSize,sizeof(nums[0]),cmp); 
		return;   	
	} 
	//此种情况说明，找到了升序的位置
	//第二步：从后开始遍历，找到，第一个大于nums[pos]的位置k，并将其交换
	for(int i=numsSize-1;i>0;i--){
		if(nums[i]>nums[pos]){
			int temp=nums[i];
			nums[i]=nums[pos];
			nums[pos]=temp;
			break;
		}
	}
	//第三步：将nums数组中从下标pos以后的数进行排序
	qsort(nums+pos+1,numsSize-pos-1,sizeof(nums[0]),cmp) ;
	
    
}
