#include<stdio.h>
#include<stdlib.h>
/*
Given an integer array of size n,
 find all elements that appear more than ? n/3 ? times.
The algorithm should run in linear time and in O(1) space.
*/
int *res=NULL;
int indexRes=0; 

void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
} 
void majorityElementHelper(int *nums,int left,int right,int len){
	if(nums==NULL||right<left){
		return;
	}
	//ѡȡmidλ�õ�ֵ��Ϊpivotֵ 
	int mid=(left+right)/2;
	int val=nums[mid];
	
	int m=left;//����ָʾ ������Ľ���У�m��ߵ�ֵ����С��val�ġ� 
	int n=left;//����ָʾ  ������Ľ���У�m~n�е�ֵ���ǵ���val�ġ�n~right���Ǵ���val�� 
	swap(nums+left,nums+mid);//��pivot����nums��һ��λ�� 
	int i=left+1;
	while(i<=right){
		if(nums[i]<val){
			swap(&nums[m++],&nums[i]);//��С��val��ֵ����m�±����� 
			swap(&nums[++n],&nums[i++]);//ʹ��n����ָ�����ұߵĵ���val���±� 
		}
		else if(nums[i]==val){
			swap(&nums[++n],&nums[i++]);
		}
		else{
			i++;
		}
	}
	if(n-m+1>=len){//�������� 
		res[indexRes++]=nums[n];
	} 
	if(m-left>=len){//С��val�ĳ��ȴ���len����˿����н� 
		majorityElementHelper(nums,left,m-1,len);
	}
	if(right-n>=len){//����val�ĳ��ȴ���len����˿����н� 
		majorityElementHelper(nums,n+1,right,len);
	}
}

int* majorityElement(int* nums, int numsSize, int* returnSize) {
    if(nums==NULL||numsSize<1){
    	*returnSize=0;
    	return NULL;
	}
	int maxLen=3;//���ֻ�������� 
	res=(int *)malloc(maxLen*sizeof(int));
	if(res==NULL){
		exit(EXIT_FAILURE);
	}
	indexRes=0;	
	majorityElementHelper(nums,0,numsSize-1,(numsSize/3)+1);
	*returnSize=indexRes;
	return res;	
}
