

#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
int paration(int *arr,int start,int end){
	if(arr==NULL||end<start){
		return -1;
	}	
	int value=arr[start];
	int index=start;
	for(int i=start+1;i<=end;i++){
		if(arr[i]<value){
			index++;
			swap(&arr[i],&arr[index]);
			
		}
	}
	swap(&arr[start],&arr[index]);
	return index;
}
void quickSortHelper(int *arr,int start,int end){
	if(arr==NULL||end<=start){
		return;
	}
	int index=paration(arr,start,end);
	quickSortHelper(arr,start,index-1);
	quickSortHelper(arr,index+1,end);
}
void quickSort(int *arr,int len){
	if(arr==NULL||len<2){
		return ;
	}
	int start=0;
	int end=len-1;
	quickSortHelper(arr,start,end);
}
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		int *arr=(int *)malloc(n*sizeof(int));
		if(arr==NULL){
			exit(EXIT_FAILURE);
		}
		for(int i=0;i<n;i++){
			scanf("%d",arr+i);
		}
		quickSort(arr,n);
		printf("排序后的结果为：");
		for(int i=0;i<n;i++){
			printf("%d ",arr[i]);
		}
		printf("\n");
	}	
}
