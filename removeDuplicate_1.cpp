
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
˼·��������һ����������temp�����п��������temp�е�Ԫ��ȫ��������ȥ�� 
*/
int removeDuplicates(int* nums, int numsSize) {
    if(nums==NULL||numsSize<1){
        return 0;
    }
    if(numsSize<=2){
        return numsSize;
    }
    //����һ�οռ������д洢
    int *temp=(int *)malloc(numsSize*sizeof(int));
    if(temp==NULL){
        exit(EXIT_FAILURE);
    }
    int index1=0;
    int index2=0;
    int count=1;
    int val; 
    for(int i=1;i<numsSize;i++){
        if(nums[i]==nums[index1]){
            count++;
        }
        else{//nums[i]��nums[index]�����,��ǰ�����������temp�����н��д洢
            val=count;
            if(count>2){
                val=2;
            }
           for(int j=0;j<val;j++){
               temp[index2]=nums[index1+j];
               index2++;
           }
           index1=i;//��index1���и���
           count=1;//��count���л�ԭ��Ϊ��һ���ж���׼��
        }
    }
    //����û�ж����Ľ��п���
	if(index1<numsSize){
		val=count;
		if(count>2){
            val=2;
       }
        for(int j=0;j<val;j++){
               temp[index2]=nums[index1+j];
               index2++;
           }
	}
    //�ٽ�temp�е���������ȥ
    for(int i=0;i<index2;i++){
    	printf("%d   ",temp[i]);
        nums[i]=temp[i];
    }
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
		printf("%d\n",removeDuplicates(arr,k));
		
	}
}
