
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/*
思路：这个不开辟额外的空间。
将数组中含有1次以上的数字全部去除掉 
*/
int removeDuplicates(int* nums, int numsSize) {
    if(nums==NULL||numsSize<1){
        return 0;
    }
    if(numsSize==1){
        return numsSize;
    }
    int index1=0;
	int index2=1;
	int count=1;
	for(int i=1;i<numsSize;i++){
		
		if(nums[index1]==nums[i])
			continue;
		//不相等就要进行拷贝
		if(i-index2!=0){//中间有Duplicate需要覆盖 
			nums[index2]=nums[i];
			index1=i;
			index2++;										
		}
		else{//不需要拷贝，但是需要更行
			index1=i;
			index2++; 
		}
	
	}
//	for(int i=0;i<index2;i++){
//		printf("%d   ",nums[i]);
//	} 
	return index2; 
    
}

int main(void){
	int k;
	while(scanf("%d",&k)!=EOF&&k>0){
		int *arr=(int *)malloc(k*sizeof(int));
		if(arr==NULL){
			exit(EXIT_FAILURE);
		}
		for(int i=0;i<k;i++){
			scanf("%d",arr+i);
		}
		int len=removeDuplicates(arr,k);
		//printf("%d\n",len);
		
	}
}
