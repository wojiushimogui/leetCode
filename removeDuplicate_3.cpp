
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
    int index=1;//用于指向即将要覆盖的位置。 
    for(int i=1;i<numsSize;i++){
    	if(nums[i]!=nums[i-1]){
    		nums[index]=nums[i];
    		index++;
		}
	}
	return index; 
    
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
		printf("%d\n",len);
		
	}
}
