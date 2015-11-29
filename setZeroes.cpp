
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) {
    if(matrix==NULL||matrixRowSize<1||matrixColSize<1){
    	return;
	}
	bool *row=(bool *)malloc(matrixRowSize*sizeof(bool));
	bool *col=(bool *)malloc(matrixColSize*sizeof(bool));
	if(row==NULL||col==NULL){
		exit(EXIT_FAILURE);
	}
	memset(row,true,matrixRowSize*sizeof(bool));
	memset(col,true,matrixColSize*sizeof(bool));
	for(int i=0;i<matrixRowSize;i++){
		for(int j=0;j<matrixColSize;j++){
				if(matrix[i][j]==0){
					row[i]=false;
					col[j]=false;
				}
	
		}
	}
	//将行初始化为零 
	for(int i=0;i<matrixRowSize;i++){
		if(!row[i]){
			for(int j=0;j<matrixColSize;j++){
				matrix[i][j]=0;
			}
		}
	}
	//列变为零 
	for(int i=0;i<matrixColSize;i++){
		if(!col[i]){
			for(int j=0;j<matrixRowSize;j++){
				matrix[j][i]=0;
			}
		}
	}
//	for(int i=0;i<matrixRowSize;i++){
//		for(int j=0;j<matrixColSize;j++){
//			printf("%d  ",matrix[i][j]);
//		}
//		printf("\n");
//	}
}

int main(void){
	int row,col;
	
	while(scanf("%d %d",&row,&col)!=EOF){
		int **matrix=(int **)malloc(row*sizeof(int *));
		if(matrix==NULL){
			exit(EXIT_FAILURE);
		}
		for(int i=0;i<row;i++){
			matrix[i]=(int *)malloc(col*sizeof(int));
			if(matrix[i]==NULL){
				exit(EXIT_FAILURE);
			}
		}
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				scanf("%d",&matrix[i][j]);
			}
		}
		setZeroes(matrix,1,1);
	}
	
} 
