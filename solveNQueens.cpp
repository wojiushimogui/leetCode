#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ***result; //ȫ�ֱ����������洢���Ľ�� 
int index_result;//������±� 
/*
n�ʺ����⣺ 
*/
bool isNQueens(int *arr,int n){
	if(arr==NULL||n<1){
		return false;
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(((j-i)==(arr[j]-arr[i]))||((j-i)==(arr[i]-arr[j]))){//ֻҪ�����������ʺ�����໥�������ͷ���false�� 
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
void solveNQueens_1(int *arr,int n,int begin){
	if(arr==NULL||n<1){
		return;
	}
	if(begin==n-1){//�õ�һ���˻ʺ���ϵ�λ�ã����Ƿ����� �����������������n�ʺ󶼲���һ��б����
		if(isNQueens(arr,n)){
			//����ǣ���ʼ����
			result[index_result]=(char **)malloc(n*sizeof(char *));
			if(result[index_result]==NULL){
				exit(EXIT_FAILURE);
			} 
			for(int k=0;k<n;k++){
				result[index_result][k]=(char *)malloc(n*sizeof(char));
				if(result[index_result][k]==NULL){
					exit(EXIT_FAILURE);
				}
				memset(result[index_result][k],'.',n*sizeof(char));//ȫ����ʼ��Ϊ'.' 
				result[index_result][k][arr[k]]='Q';//���ʺ��λ�����ַ�'Q'��ֵ 
			}
			index_result++;
			 
		} 
		
	}
	for(int i=begin;i<n;i++){
			swap(arr+begin,arr+i);
			solveNQueens_1(arr,n,begin+1);
			swap(arr+begin,arr+i);
	} 
}
char*** solveNQueens(int n, int* returnSize) {
    if(n<1){
    	return 0;
	}
	int total=n*n*n;//����²������ܹ�����Ҫ���λ�ã���n*n�֣������������������ 
	result=(char ***)malloc(total*sizeof(char **));
	index_result=0;
	if(result==NULL){
		exit(EXIT_FAILURE);
	} 
	int *arr=(int *)malloc(n*sizeof(int));
	if(arr==NULL){
		exit(EXIT_FAILURE);
	}
	for(int i=0;i<n;i++){
		arr[i]=i;
	}
	
	solveNQueens_1(arr,n,0);
	*returnSize=index_result;
	return result;
}

int main(void){
	int n;
	while(scanf("%d",&n)!=EOF&&n>0){
		int returnSize=0;
		char ***result1=solveNQueens( n, &returnSize);
		for(int i=0;i<returnSize;i++){
			printf("��%d�ֽ������:\n",i);
			for(int j=0;j<n;j++){
				for(int k=0;k<n;k++){
					printf("%c  ",result1[i][j][k]);
				}
				printf("\n");
			}
			printf("\n\n");
		}
	}
	return 0;
}
