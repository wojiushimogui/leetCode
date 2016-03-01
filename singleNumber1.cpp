#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
˼·����Ȼ����֪����δ�ֻ��һ��������һ���������������ε������еõ��������
��ˣ����Ǿ�Ӧ����취�����������ֵ������������У��ұ�֤��������������ÿ���������������Ρ� 
*/
/*
�����Ĺ��ܣ��ж����� num�ڵ� index����λ�Ƿ�Ϊ1 
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
	//��һ�����õ�������ͬ���������ֵ 
	int aXorB=0;
	for(int i=0;i<numsSize;i++){
		aXorB^=nums[i];
	}
	//�ڶ������������ֵ�Ľ�������ұߵģ���nums�ֳ����������顣
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
