#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void sortColors(int* nums, int numsSize) {
    if(nums==NULL||numsSize<2){
    	return;
	}
	int front=0;
	int back=numsSize-1;
	for(int i=0;i<=back;i++){
		if(nums[i]==0){
			swap(&nums[front],&nums[i]);
			front++;
		}
		else if(nums[i]==2){
			swap(&nums[back],&nums[i]);//ע�⣺�����iҪ��һ��������Ϊ���������һ���򻻵�ǰ������Ͳ��ٽ��м�飬���ǲ��е� 
			back--;
			i--;
		}
	}
	for(int i=0;i<numsSize;i++){
		printf("%d  ",nums[i]);
	} 
	printf("\n");	 
}
int main(void){
	int n;
	while(scanf("%d",&n)!=EOF){
		int *arr=(int *)malloc(n*sizeof(int));
		if(arr==NULL){
			exit(EXIT_FAILURE);
		}
		for(int i=0;i<n;i++){
			scanf("%d",arr+i);
		}
//		for(int j=0;j<n;j++){
//			printf("%d    ",arr[j]);
//		}
		sortColors(arr,n);
	}
} 
 
