#include<stdio.h>
#include<stdlib.h>


/**
 * Return an array of arrays.
 * Note: The returned array must be malloced, assume caller calls free().
 */
//此题比较简单；2015年11月21日20:00:12 
int** generateMatrix(int n) {
    if(n<0){
    	return NULL;
	}
	int row=n;
	int col=n;
	
	//分配一个空间来保存结果
	int **result=(int **)malloc(row*sizeof(int *));
	if(result==NULL){
		exit(EXIT_FAILURE);
	} 
	for(int j=0;j<row;j++){
		result[j]=(int *)malloc(col*sizeof(int));
		if(result[j]==NULL){
			exit(EXIT_FAILURE);
		}
	}
	int nx[4]={1,0,-1,0};
	int ny[4]={0,1,0,-1};
	int i=0;//用来控制方向；
	int x=-1;
	int y=0;
	int value=1;
	while(row>0&&col>0){
		int k;
		if(i%2==0){
			k=col;
			row--;
		}
		else{
			k=row;
			col--;
		}
		while(k>0){
			x+=nx[i];
			y+=ny[i];
			result[y][x]=value;
			value++;
			k--;
		}
		i=(i+1)%4;
	}
	return result; 
}

int main(void){
	int n;
	while(scanf("%d",&n)!=EOF&&n>0){
		int **result=generateMatrix(n);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				printf("%d  ",result[i][j]);
			}
			printf("\n"); 
		}
	}
}
