#include<stdio.h>
#include<stdlib.h>
#include<Math.h>
#include<string.h>
#define N 32 
int singleNumber_v1(int* nums, int numsSize) {
    if(nums==NULL||numsSize<1){
    	return 0;
	}
	int *bitNum=(int *)malloc(N*sizeof(int));
	if(bitNum==NULL){
		exit(EXIT_FAILURE);
	}
	memset(bitNum,0,N*sizeof(int));
	for(int i=0;i<numsSize;i++){
		int value=nums[i];
		for(int j=0;j<N;j++){
			bitNum[j]+=(value&1);
			value=value>>1;
		}
	}
	int res=0;
	for(int i=0;i<N;i++){
		bitNum[i]=bitNum[i]%3;
		res|=(bitNum[i]<<i);
	}
	return res;	
}

int main(void){
	int len=3;
	int nums[len]={2,2,2,3};
	int res=singleNumber_v1(nums,len);
	printf("%d  ",res);
	return 0;
}
