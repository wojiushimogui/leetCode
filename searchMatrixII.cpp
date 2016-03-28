

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    if(matrix==NULL||matrixRowSize<1||matrixColSize<1){
    	return false;
	}
	if(target<matrix[0][0]||target>matrix[matrixRowSize-1][matrixColSize-1]){
		return false;
	}
	//��ʼѰ��
	/*
	˼·���Ӿ�������Ͻǿ�ʼѰ�ң�����������Ͻǵ�Ԫ�أ�
	��ȥ����һ�У����С�����Ͻǵ�Ԫ�أ���ȥ����һ�С� 
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
