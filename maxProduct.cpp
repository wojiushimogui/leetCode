#include<stdio.h>
#include<stdlib.h>

int max(int a,int b){
	return a>b?a:b;
}
/*
�㷨:����Ʒֵ��Ҫ���������ؾ�������һΪ 0Ԫ�أ��ڶ�Ϊ�����ĸ���
���ڱ����Ĺ����У������� 0Ԫ�أ���������µľ���
1�������ʱ��ֵΪ��������lowpoint����highpoint��£��ʹ�õ�ǰֵΪ����
2�������ʱ��ֵΪ����������������ʱ��ֵ��lowpoint�������0Ԫ�ص�λ��ָ���һ������ֵ 
*/
int maxProduct(int* nums, int numsSize) {
    if(nums==NULL||numsSize<1){
    	return 0;
	}
	if(numsSize==1){
		return nums[0];
	}
	//��˫ָ��������
	int lowpoint=0;
	int highpoint=0;
	int maxValue=INT_MIN;
	int curValue=1;
	while(highpoint<numsSize){
		if(nums[highpoint]==0&&curValue<0&&lowpoint<highpoint-1){
			for(;curValue<0&&lowpoint<highpoint-1;lowpoint++){//ֱ��curValueΪ�� 
				curValue/=nums[lowpoint];
				maxValue=max(maxValue,curValue);
			} 
									
		}
		else if(nums[highpoint]==0){
			maxValue=max(maxValue,0);//ע�� 
			highpoint++;
			lowpoint=highpoint;
			curValue=1;
		}
		else{
			curValue*=nums[highpoint++];
			maxValue=max(maxValue,curValue);
		}
	}
	for(;curValue<0&&lowpoint<numsSize-1;lowpoint++){//��curValueС����ʱ��������lowpoint 
		curValue/=nums[lowpoint];
		maxValue=max(maxValue,curValue);
	} 
	return maxValue;
}

int main(void){
	int len=7;
	int arr[len]={3,-2,-3,-3,1,3,0};
	int res=maxProduct(arr, len);
	printf("%d   ",res);
	
}
