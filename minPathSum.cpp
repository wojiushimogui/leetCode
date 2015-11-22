#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
˼·������ĵ��յ�����·������min(�ұ߽ڵ�����·��,���·��ڵ�Ķ�·�� ); 
*/

int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    if(grid==NULL||gridRowSize<1||gridColSize<1){
    	return 0;
	}
	if(gridRowSize==1&&gridColSize==1){
		return grid[0][0];
	}
	//�������̵�ı�������ʾ 
	int m=gridRowSize;
	int n=gridColSize;
	//����һ�οռ���������
    int **result=(int **)malloc(m*sizeof(int *));
    if(result==NULL){
        exit(EXIT_FAILURE);
    }
    for(int i=0;i<m;i++){
        result[i]=(int *)malloc(n*sizeof(int));
        if(result[i]==NULL){
            exit(EXIT_FAILURE);
        }
        memset(result[i],0,n*sizeof(int));//��ʼ��Ϊ�� 
    }
    result[m-1][n-1]=grid[m-1][n-1];
	//���һ��   
    for(int i=m-2;i>=0;i--){
    		result[i][n-1]=result[i+1][n-1]+grid[i][n-1];
    }
    //���һ��Ϊ �����������֮ǰΪ1��֮��Ϊ�㣬��ʾ���ɴ   
    for(int i=n-2;i>=0;i--){
    		result[m-1][i]=result[m-1][i+1]+grid[m-1][i];
    }
    for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
        		result[i][j]=((result[i+1][j]<=result[i][j+1])?result[i+1][j]:result[i][j+1])+grid[i][j];
    			//result[i][j]=min(result[i+1][j],result[i][j+1])+grid[i][j];			
        }
    }
    return result[0][0]; 
	
	
}
