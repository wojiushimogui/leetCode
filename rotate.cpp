#include<stdio.h>
#include<stdlib.h>
/*
思路：将数组中前面k个元素逆序，以及将数组后面的（n-k）个元素 逆序
最后将整体逆序即可。 
*/
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
//函数功能：将数组nums进行逆序 
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
