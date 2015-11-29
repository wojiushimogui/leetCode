

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    if(matrix==NULL||matrixRowSize<1||matrixColSize<1){
        return false;
    }
    if(target<matrix[0][0]||target>matrix[matrixRowSize-1][matrixColSize-1]){
        return false;
    }
    for(int i=0;i<matrixRowSize;i++){
        for(int j=0;j<matrixColSize;j++){
            if(matrix[i][j]==target){
                return true;
            }
        }
    }
    return false;
}
