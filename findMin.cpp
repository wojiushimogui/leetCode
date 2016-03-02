#include<stdio.h>
#include<stdlib.h>

//�������ܣ�������ת��Ϊʮ������ 
int arrayToNum(int* nums, int numsSize){
	if(nums==NULL||numsSize<1){
    	return 0;
	}
	int res=0;
	for(int i=0;i<numsSize;i++){
		res=res*10+nums[i];
	}
	return res;
}
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
//�������ܣ�������������� 
void reverse(int* nums, int numsSize){
	if(nums==NULL||numsSize<1){
    	return;
	}
	int begin=0;
	int end=numsSize-1;
	while(begin<end){
		swap(&nums[begin],&nums[end]);
		begin++;
		end--;
	} 
} 
int findMin(int* nums, int numsSize) {
    if(nums==NULL||numsSize<1){
    	return 0;
	}
	//�����еĽ����Ѱ����С 
	//����һ���м�����
	int *temp=(int *)malloc(numsSize*sizeof(int));
	if(temp==NULL){
		exit(EXIT_FAILURE);
	} 
	int minRes=arrayToNum(nums,numsSize);
	for(int i=0;i<numsSize;i++){		
		for(int j=0;j<numsSize;j++){
			temp[j]=nums[j];
		}
		//���������ұ���תiλ:��������ǰ��ģ�numsSize-i����Ԫ�����򣬺����i��Ԫ����������������򼴿���ɡ� 
		reverse(temp,numsSize-i);
		reverse(temp+numsSize-i,i);
		reverse(temp,numsSize); 
		int res=arrayToNum(temp,numsSize);
		if(res<minRes){
			minRes=res;
		}
	}
	return minRes;
}
