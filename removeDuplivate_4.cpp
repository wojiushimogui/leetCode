
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
*/

/*
˼·���Ȱ����е�ǰ��λ�Ž�ȥ��Ȼ���ú���ĺ��Ѿ��Ž�ȥ�������λ�Ƚϣ������ͬ����ô�ӵ��������ͬ���ͷŽ�ȥ��
*/
int removeDuplicates(int* nums, int numsSize) {
    if(nums==NULL||numsSize<1){
        return 0;
    }
    if(numsSize<=2){
        return numsSize;
    }
    int index=2;
    for(int i=2;i<numsSize;i++){
    	if(nums[i]!=nums[index-1]||nums[i]!=nums[index-2]){
    		nums[index]=nums[i];
			index++;
		}
	}
	for(int i=0;i<index;i++){
		printf("%d  ",nums[i]);
	}
	printf("\n");
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
		printf("%d\n",removeDuplicates(arr,k));
		
	}
}
