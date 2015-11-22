#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
�����ÿռ任ȡʱ���˼·������
ֻ����������ϰ���Ĵ�����Ϊ���Ըõ�ĵ��յ�Ŀɴ�·����Ϊ��
*/
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    if(obstacleGrid==NULL||obstacleGridRowSize<1||obstacleGridColSize<1){
        return 0;
    }
    int m=obstacleGridRowSize;
    int n=obstacleGridColSize;
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
    //���һ��Ϊ �������Ϲ���֮ǰΪ1��֮��Ϊ�㣬��ʾ���ɴ   
    for(int i=m-1;i>=0;i--){
    	if(obstacleGrid[i][n-1]==0){
    		result[i][n-1]=1;
		}
		else{
			break;
		}
    }
    //���һ��Ϊ �����������֮ǰΪ1��֮��Ϊ�㣬��ʾ���ɴ   
    for(int i=n-1;i>=0;i--){
    	if(obstacleGrid[m-1][i]==0){
    		result[m-1][i]=1;
		}
		else{
			break;
		}
    }
    for(int i=m-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
        	if(obstacleGrid[i][j]==0){
    			result[i][j]=result[i+1][j]+result[i][j+1];
			}
			
        }
    }
    return result[0][0];
}
