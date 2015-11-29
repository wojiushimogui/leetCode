#include<stdio.h>
#include<stdlib.h>
#include<string.h>
bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    if(matrix==NULL||matrixRowSize<1||matrixColSize<1){
        return false;
    }
    if(target<matrix[0][0]||target>matrix[matrixRowSize-1][matrixColSize-1]){
        return false;
    }
    int beginRow=0;
    int beginCol=0;
    int endRow=matrixRowSize-1;
    int endCol=matrixColSize-1;
    while(beginRow<endRow){
    	int midRow=beginRow+(endRow-beginRow)/2;
    	int midCol=beginCol+(endCol-beginCol)/2;
    	if(matrix[midRow][midCol]==target){
    		return true;
		}
		else if(matrix[midRow][midCol]>target){
			if(matrix[midRow][0]>target){
				endRow=midRow-1;
			}
			else{
				beginRow=midRow;
				endRow=midRow;
			}
			
		}
		else{//matrix[midRow][midCol]<target
			if(matrix[midRow][endCol]<target){
				beginRow=midRow+1;
			}
			else{
				beginRow=midRow;
				endRow=midRow;
			}
		}
	}
	while(beginCol<=endCol){
		int midCol=beginCol+(endCol-beginCol)/2;
		if(matrix[beginRow][midCol]==target){
			return true;
		}
		else if(matrix[beginRow][midCol]>target){
			endCol=midCol-1;
		}
		else {
			beginCol=midCol+1;
		}
	}
    return false;
}
