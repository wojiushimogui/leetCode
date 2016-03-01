#include<stdio.h>
#include<stdlib.h>
/*
˼·����������ǰ��k��Ԫ�������Լ����������ģ�n-k����Ԫ�� ����
����������򼴿ɡ� 
*/
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
//�������ܣ�������nums�������� 
void reverse(int *nums,int numsSize){
	if(nums==NULL||numsSize<1){
		return ;
	} 
	int begin=0;
	int end=numsSize-1;
	while(begin<end){
		swap(&nums[begin],&nums[end]);
		begin++;
		end--;
	}
}
void rotate(int* nums, int numsSize, int k) {
    if(nums==NULL||numsSize<1||k<0){
    	return;
	} 
	k=k%numsSize;
	reverse(nums,k);
	reverse(nums+k,numsSize-k);
	reverse(nums,numsSize); 
}
