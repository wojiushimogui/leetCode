
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/*
˼·����������ٶ���Ŀռ䡣
�������к���1�����ϵ�����ȫ��ȥ���� 
*/
int removeDuplicates(int* nums, int numsSize) {
    if(nums==NULL||numsSize<1){
        return 0;
    }
    int index=1;//����ָ�򼴽�Ҫ���ǵ�λ�á� 
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
