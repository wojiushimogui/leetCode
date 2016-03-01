#include<stdio.h>
#include<stdlib.h>
/*
˼· 
*/
int singleNumber(int* nums, int numsSize) {
    if(nums==NULL||numsSize<1){
    	return 0;
	} 
	int xorValue=nums[0];
	for(int i=1;i<numsSize;i++){
		xorValue^=nums[i];
	}
	return xorValue;
}

int main(void){
	printf("%d   ",1^1);
	printf("%d",1^0);
}
