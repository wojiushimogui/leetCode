#include<stdio.h>
#include<stdlib.h>
#define N  4
void rotate(int** matrix, int matrixRowSize, int matrixColSize) {
    if(matrix==NULL||matrixRowSize<1||matrixColSize<1){
        return;
    }
//    for(int i=0;i<matrixRowSize;i++){
//        for(int j=0;j<matrixColSize;j++){
//            printf("%d  ",matrix[i][j]);
//        }
//        printf("\n");
//    }
    int temp=0;
    int row=0;
	int col=0; 
	int circleRow=0;
	int circleCol=0;
    //��ʼ��������ȦΪ��Ԫ
	int circleNum=matrixRowSize/2; 
    for(int i=0;i<circleNum;i++){
    	circleRow=i;
    	circleCol=i;
    	for(int k=0;k<matrixRowSize-1-2*i;k++){//����Ҫ��һ�£� 
    		row=circleRow;
    		col=circleCol+k;
    		int preTemp=matrix[row][col];
    		for(int j=0;j<N;j++){//ÿһ�ֽ�����4�ν��� 
        	
        	int curTemp=matrix[col][matrixRowSize-1-row];//�Ƚ���ֵ���� 
            matrix[col][matrixRowSize-1-row]=preTemp;//�� matrix[row][col]�� matrix[col][matrixRowSize-1-row]
            printf("%d   ",matrix[col][matrixRowSize-1-row]);
            int temp1=col;
            int temp2=matrixRowSize-1-row;
            row=temp1;
            col=temp2;
            preTemp=curTemp;
        	}	   		
		}
        
    }
    printf("\n");
    //������ȥ
    for(int i=0;i<matrixRowSize;i++){
        for(int j=0;j<matrixColSize;j++){
            printf("%d  ",matrix[i][j]);
        }
        printf("\n");
    }
    
}
#define M  4
int main(void){
	int **arr=(int **)malloc(M*sizeof(int *));
	for(int i=0;i<M;i++){
		arr[i]=(int *)malloc(M*sizeof(int));
		
	}
	int count=1;
	for(int i=0;i<M;i++){
		for(int j=0;j<M;j++){
			arr[i][j]=count;
			count++;
		}
	}
	
	rotate(arr,M,M);
}
