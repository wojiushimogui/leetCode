#include<stdio.h>
#include<stdlib.h>
#include<string.h>


//统计个数这个就要简单多了
//2015年11月16日21:10:33 
bool isNQueens(int *arr,int n){
	if(arr==NULL||n<1){
		return false;
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(((j-i)==(arr[j]-arr[i]))||(j-i)==(arr[i]-arr[j])){
				return false;
			}
		}
	}
	return true;
}
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void totalNQueens(int *arr,int n,int begin,int *total){
	if(arr==NULL||n<1){
		return;
	}
	if(begin==n-1){
		//判断是否符合要求
		if(isNQueens(arr,n)){
			(*total)++;
		} 
	}
	for(int i=begin;i<n;i++){
		swap(arr+begin,arr+i);
		totalNQueens(arr,n,begin+1,total);
		swap(arr+begin,arr+i);
	}
}
int totalNQueens(int n) {
    if(n<1){
    	return 0;
	}
	int *arr=(int *)malloc(n*sizeof(int));
	if(arr==NULL){
		exit(EXIT_FAILURE);
	}
	for(int i=0;i<n;i++){
		arr[i]=i;
	}
	int total=0;
	totalNQueens(arr,n,0,&total);
	return total;
}

int main(void){
	int n;
	while(scanf("%d",&n)!=EOF&&n>0){
		int result=totalNQueens( n);
		printf("%d\n",result);
	}
	return 0;
}
