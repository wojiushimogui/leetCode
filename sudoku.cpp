#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

/*
˼·������ֻ��Ҫ���Ǽ��һ��Sudoku�Ƿ���Ч��������Ҫ������һ��sudoku��
�������ֻ��Ҫ����sudoku�Ķ�������鼴�ɡ� 
sudoku��Ҫ�����£�
1��Each row must have the numbers 1-9 occuring just once. 
2��Each column must have the numbers 1-9 occuring just once
3��And the numbers 1-9 must occur just once in each of the 9 sub-boxes of the grid. 
*/
//sudoku��һ��9*9�ľ��󣬲�֪������boardRowSize��boardColSize����������� 
bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    if(board==NULL||boardRowSize!=9||boardColSize!=9){//��Ч�Լ�� 
    	return false;
	} 
	int *row=(int *)malloc(boardRowSize*sizeof(int));
	if(row==NULL)
		exit(EXIT_FAILURE);
	int *col=(int *)malloc(boardColSize*sizeof(int));
	if(col==NULL)
		exit(EXIT_FAILURE);
	for(int i=0;i<9;i++){
		//���ÿ��ÿ�ж���Ҫ��row��col���������������� 
		memset(row,0,9*sizeof(int));
		memset(col,0,9*sizeof(int));
		for(int j=0;j<9;j++){
			if(board[i][j]!='.'){//���ÿ��
			//�� ����ʽ�г��ּ�  1��ԭ���ǣ�������±���㿪ʼ��������Ϊ1~9�����Ϊ��1~9�洢��row�������±�Ϊ0~8��λ�� 
				if(row[board[i][j]-'1']>0) //˵���Ѿ����ڣ�����ĳһ�д�����ͬ�����֣��� ����false 
					return false;
				else {
					row[board[i][j]-'1']++;
				}
				
			}
			
			if(board[j][i]!='.') {//���ÿ�� 
				if(col[board[j][i]-'1']>0) //˵���Ѿ����ڣ�����ĳһ�д�����ͬ�����֣��� ����false 
					return false;
				else {
					col[board[j][i]-'1']++;
				}
			}
			
		}
	}
	//���ż��ÿ��3*3���ӿ� �е������Ƿ���Ψһ��
	for(int i=0;i<9;i+=3){//����Ϊ���� 
		for(int j=0;j<9;j+=3){
			//���ÿ��3*3���ӿ�ʱ����Ҫ��row��col���������������� 
			memset(row,0,9*sizeof(int));
		//	memset(col,0,9*sizeof(int));
			for(int m=0;m<3;m++){
				for(int n=0;n<3;n++){
					if(board[i+m][j+n]!='.'){
						if(row[board[i+m][j+n]-'1']>0) return false;
						else row[board[i+m][j+n]-'1']++;
					}
				}
			} 
		} 
	}
	//������涼��ȷ���򷵻�true
	return true; 
}
