#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
int paration(int *arr,int left,int right){
	if(arr==NULL||left>=right){
		return -1;
	}
	int index=left;
	int temp=arr[left];
	for(int i=left+1;i<=right;i++){
		if(arr[i]<temp){
			index++;
			swap(&arr[i],&arr[index]);
		}
	}
	swap(&arr[index],&arr[left]);
	return index;
}
void quickSort(int *arr,int left,int right){
	if(arr==NULL||left>=right){
		return;
	}
	int index=paration(arr,left,right);
	quickSort(arr,left,index-1);
	quickSort(arr,index+1,right);
}

int main(void){
	int arr[100];
	int n;
	while(scanf("%d",&n)!=EOF&&n>0){
		for(int i=0;i<n;i++){
			scanf("%d",&arr[i]);
		}
		quickSort(arr,0,n-1);
		for(int i=0;i<n;i++){
			printf("%d  ",arr[i]);
		}
		printf("\n");
		
	}
}
