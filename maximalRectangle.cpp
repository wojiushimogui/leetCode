#include<stdio.h>
#include<stdlib.h>

int maximalRectangle(char** matrix, int matrixRowSize, int matrixColSize) {
    if(matrix==NULL){
    	return 0;
	}
	int lowRow=0,bigRow=matrixRowSize-1;
	int lowCol=0,bigCol=matrixColSize-1;
	while(lowRow<matrixRowSize){
		int i=0;
		for(;i<matrixColSize;i++){
			if(matrix[lowRow][i]!='0'){
				break;
			}
		}
		if(i<matrixColSize){
			break;
		}
		else{
			lowRow++;
		}
	}
	while(bigRow>=0){
		int i=0;
		for(;i<matrixColSize;i++){
			if(matrix[bigRow][i]!='0'){
				break;
			}
		}
		if(i<matrixColSize){
			break;
		}
		else{
			bigRow--;
		}
	}
	while(lowCol<matrixColSize){
		int i=0;
		for(;i<matrixRowSize;i++){
			if(matrix[i][lowCol]!='0'){
				break;
			}
		}
		if(i<matrixRowSize){
			break;
		}
		else{
			lowCol++;
		}
	}
	while(bigCol>=0){
		int i=0;
		for(;i<matrixRowSize;i++){
			if(matrix[i][bigCol]!='0'){
				break;
			}
		}
		if(i<matrixRowSize){
			break;
		}
		else{
			bigCol--;
		}
	}
	if(bigRow>=lowRow&&bigCol>=lowRow){
		return (bigRow-lowRow+1)*(bigCol-lowCol+1);
	}
	else{
		return 0;
	}   
}

int main(void){
	int matrixRowSize=0;
	int matrixColSize=0;
	while(scanf("%d%d",&matrixRowSize,&matrixColSize)!=EOF){
		char **matrix=(char **)malloc(matrixRowSize*sizeof(char *));
		if(matrix==NULL){
			exit(EXIT_FAILURE);
		}
		for(int i=0;i<matrixRowSize;i++){
			*matrix=(char *)malloc(matrixColSize*sizeof(char));
			if(*matrix==NULL){
				exit(EXIT_FAILURE);
			}
		}
		for(int i=0;i<matrixRowSize;i++){
			for(int j=0;j<matrixColSize;j++){				
				scanf("%c",&matrix[i][j]);
			}
		}
		int res=maximalRectangle(matrix,matrixRowSize,matrixColSize);
		printf("%d\n",res);
	}
	
}

/*
public class Solution {
public int maximalRectangle(char[][] matrix) {
    if(matrix == null || matrix.length == 0 || matrix[0].length == 0) return 0;

    int[] height = new int[matrix[0].length];
    for(int i = 0; i < matrix[0].length; i ++){
        if(matrix[0][i] == '1') height[i] = 1;
    }
    int result = largestInLine(height);
    for(int i = 1; i < matrix.length; i ++){
        resetHeight(matrix, height, i);
        result = Math.max(result, largestInLine(height));
    }

    return result;
}

private void resetHeight(char[][] matrix, int[] height, int idx){
    for(int i = 0; i < matrix[0].length; i ++){
        if(matrix[idx][i] == '1') height[i] += 1;
        else height[i] = 0;
    }
}    

public int largestInLine(int[] height) {
    if(height == null || height.length == 0) return 0;
    int len = height.length;
    Stack<Integer> s = new Stack<Integer>();
    int maxArea = 0;
    for(int i = 0; i <= len; i++){
        int h = (i == len ? 0 : height[i]);
        if(s.isEmpty() || h >= height[s.peek()]){
            s.push(i);
        }else{
            int tp = s.pop();
            maxArea = Math.max(maxArea, height[tp] * (s.isEmpty() ? i : i - 1 - s.peek()));
            i--;
        }
    }
    return maxArea;
}

*/
