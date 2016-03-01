#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
思路：既然我们知道如何从只有一个数出现一次其他数出现两次的数组中得到这个数。
因此，我们就应该想办法将这两个数分到两个子数组中，且保证子数组中其它的每个数都出现了两次。 
*/
/*
函数的功能：判断数字 num在第 index比特位是否为1 
*/
bool isBitOne(int num,int index){
	if((num>>index)&0x01){
		return true;
	} 
	return false;
}
int* singleNumber(int* nums, int numsSize, int* returnSize) {
    if(nums==NULL||numsSize<1){
    	return NULL;
	}
	//第一步：得到两个不同的数的异或值 
	int aXorB=0;
	for(int i=0;i<numsSize;i++){
		aXorB^=nums[i];
	}
	//第二步：根据异或值的结果中最右边的１将nums分成两个子数组。
	int oneBitIndex=0;
	while(aXorB){
		if(aXorB&0x01){
			break;
		}
		aXorB>>=1;
		oneBitIndex++;
	} 
	*returnSize=2; 
	int *res=(int *)malloc((*returnSize)*sizeof(int));
	if(res==NULL){
		exit(EXIT_FAILURE);
	}
	memset(res,0,(*returnSize)*sizeof(int));
	int secondRes=0;
	for(int i=0;i<numsSize;i++){
		if(isBitOne(nums[i],oneBitIndex)){
			res[0]^=nums[i];
		}
		else{
			res[1]^=nums[i];
		}
	}
	return res;
}
