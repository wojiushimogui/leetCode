

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    if(matrix==NULL||matrixRowSize<1||matrixColSize<1){
    	return false;
	}
	if(target<matrix[0][0]||target>matrix[matrixRowSize-1][matrixColSize-1]){
		return false;
	}
	//开始寻找
	/*
	思路：从矩阵的左上角开始寻找，如果大于右上角的元素，
	则去除这一行，如果小于右上角的元素，则去除这一列。 
	*/ 
	int row=0;
	int col=matrixColSize-1;
	while(row<matrixRowSize&&col>=0){
		int temp=matrix[row][col];
		if(temp==target){
			return true;
		}
		else if(temp<target){
			row++;			
		}
		else if(temp>target){
			col--;
		}
	}
	return false;
}
