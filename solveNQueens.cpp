#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ***result; //全局变量，用来存储最后的结果 
int index_result;//结果的下标 
/*
n皇后问题： 
*/
bool isNQueens(int *arr,int n){
	if(arr==NULL||n<1){
		return false;
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(((j-i)==(arr[j]-arr[i]))||((j-i)==(arr[i]-arr[j]))){//只要发现有两个皇后可以相互攻击，就返回false； 
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
	if(begin==n-1){//得到一个八皇后组合的位置，看是否满足 不被攻击的情况，即n皇后都不在一条斜线上
		if(isNQueens(arr,n)){
			//如果是，则开始保存
			result[index_result]=(char **)malloc(n*sizeof(char *));
			if(result[index_result]==NULL){
				exit(EXIT_FAILURE);
			} 
			for(int k=0;k<n;k++){
				result[index_result][k]=(char *)malloc(n*sizeof(char));
				if(result[index_result][k]==NULL){
					exit(EXIT_FAILURE);
				}
				memset(result[index_result][k],'.',n*sizeof(char));//全部初始化为'.' 
				result[index_result][k][arr[k]]='Q';//将皇后的位置用字符'Q'赋值 
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
	int total=n*n*n;//这里，猜测他的总共符合要求的位置，共n*n种，如果不够，则再扩充 
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
			printf("第%d种结果如下:\n",i);
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
