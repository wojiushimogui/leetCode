#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
还是用空间换取时间的思路来做，
只不过这里对障碍物的处理方法为：对该点的到终点的可达路径设为零
*/
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    if(obstacleGrid==NULL||obstacleGridRowSize<1||obstacleGridColSize<1){
        return 0;
    }
    int m=obstacleGridRowSize;
    int n=obstacleGridColSize;
    //开辟一段空间来保存结果
    int **result=(int **)malloc(m*sizeof(int *));
    if(result==NULL){
        exit(EXIT_FAILURE);
    }
    for(int i=0;i<m;i++){
        result[i]=(int *)malloc(n*sizeof(int));
        if(result[i]==NULL){
            exit(EXIT_FAILURE);
        }
        memset(result[i],0,n*sizeof(int));//初始化为零 
    }
    //最后一列为 从下往上故障之前为1，之后为零，表示不可达；   
    for(int i=m-1;i>=0;i--){
    	if(obstacleGrid[i][n-1]==0){
    		result[i][n-1]=1;
		}
		else{
			break;
		}
    }
    //最后一行为 从右往左故障之前为1，之后为零，表示不可达；   
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
