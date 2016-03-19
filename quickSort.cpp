#include<stdio.h>
#include<stdlib.h> 

void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
int paration(int *arr,int left,int right){
	if(arr!=NULL&&left<right){
		int value=arr[left];//选取第一个数作为主元
		int index=left;
		for(int i=left+1;i<=right;i++){
			if(arr[i]<value){
				index++;
				swap(arr+i,arr+index);				
			}
			else{
				continue;
			}
		}
		swap(arr+left,arr+index); 
		return index;
	}
		
}
void quickSortHelper(int *arr,int left,int right){
	int index;
	if(left<right){
		index=paration(arr,left,right);
		quickSortHelper(arr,left,index-1);
		quickSortHelper(arr,index+1,right);
	}
}

void quickSort(int *arr,int len){
	if(arr==NULL||len<1){
		return;
	}
	quickSortHelper(arr,0,len-1);	
}
int main(void){
	int k;
	int *arr;
	while(scanf("%d",&k)!=EOF){
		arr=(int *)malloc(k*sizeof(int ));
		if(arr==NULL){
			exit(EXIT_FAILURE);
		}
		for(int i=0;i<k;i++){
			scanf("%d",arr+i);
		}
		quickSort(arr,k);
		for(int i=0;i<k;i++){
			printf("%d  ",arr[i]);
		}
	}
}
