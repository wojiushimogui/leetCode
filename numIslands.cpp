#include<stdio.h>
#include<stdlib.h>
void DFS(char** grid, int gridRowSize, int gridColSize,int row,int col){
	if(grid==NULL||gridRowSize<1||gridColSize<1
		||row<0||gridRowSize<=row||col<0||gridColSize<=col){
    	return ;
	}
	if(grid[row][col]=='1'){
		grid[row][col]='0'; 
		//四个方向进行搜索 
		DFS(grid,gridRowSize,gridColSize,row,col+1);
		DFS(grid,gridRowSize,gridColSize,row,col-1);
		DFS(grid,gridRowSize,gridColSize,row+1,col);
		DFS(grid,gridRowSize,gridColSize,row-1,col);
	}
}

int numIslands(char** grid, int gridRowSize, int gridColSize) {
    if(grid==NULL||gridRowSize<1||gridColSize<1){
    	return 0;
	}
	int count=0;
	for(int i=0;i<gridRowSize;i++){
		for(int j=0;j<gridColSize;j++){
			if(grid[i][j]=='1'){//利用深度优先搜索来进行遍历标记
				count++; 
				DFS(grid,gridRowSize,gridColSize,i,j);
			}
		}
	}
}
