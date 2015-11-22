#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
思路：个点的到终点的最短路径等于min(右边节点的最短路径,正下方节点的短路径 ); 
*/

int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    if(grid==NULL||gridRowSize<1||gridColSize<1){
    	return 0;
	}
	if(gridRowSize==1&&gridColSize==1){
		return grid[0][0];
	}
	//换两个短点的变量来表示 
	int m=gridRowSize;
	int n=gridColSize;
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
    result[m-1][n-1]=grid[m-1][n-1];
	//最后一列   
    for(int i=m-2;i>=0;i--){
    		result[i][n-1]=result[i+1][n-1]+grid[i][n-1];
    }
    //最后一行为 从右往左故障之前为1，之后为零，表示不可达；   
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
