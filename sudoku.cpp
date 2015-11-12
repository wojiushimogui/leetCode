#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

/*
思路：由于只是要我们检查一个Sudoku是否有效。并不是要我们求一个sudoku，
因此我们只需要按照sudoku的定义来检查即可。 
sudoku的要求如下：
1、Each row must have the numbers 1-9 occuring just once. 
2、Each column must have the numbers 1-9 occuring just once
3、And the numbers 1-9 must occur just once in each of the 9 sub-boxes of the grid. 
*/
//sudoku是一个9*9的矩阵，不知道参数boardRowSize和boardColSize的意义在那里。 
bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
    if(board==NULL||boardRowSize!=9||boardColSize!=9){//有效性检查 
    	return false;
	} 
	int *row=(int *)malloc(boardRowSize*sizeof(int));
	if(row==NULL)
		exit(EXIT_FAILURE);
	int *col=(int *)malloc(boardColSize*sizeof(int));
	if(col==NULL)
		exit(EXIT_FAILURE);
	for(int i=0;i<9;i++){
		//检查每行每列都需要将row和col数组进行清零操作。 
		memset(row,0,9*sizeof(int));
		memset(col,0,9*sizeof(int));
		for(int j=0;j<9;j++){
			if(board[i][j]!='.'){//检查每行
			//上 面表达式中出现减  1的原因是，数组的下标从零开始，而数字为1~9，因此为将1~9存储到row数组中下标为0~8的位置 
				if(row[board[i][j]-'1']>0) //说明已经存在，即有某一行存在相同的数字，则 返回false 
					return false;
				else {
					row[board[i][j]-'1']++;
				}
				
			}
			
			if(board[j][i]!='.') {//检查每列 
				if(col[board[j][i]-'1']>0) //说明已经存在，即有某一列存在相同的数字，则 返回false 
					return false;
				else {
					col[board[j][i]-'1']++;
				}
			}
			
		}
	}
	//接着检查每个3*3的子框 中的数字是否是唯一的
	for(int i=0;i<9;i+=3){//以三为步长 
		for(int j=0;j<9;j+=3){
			//检查每个3*3的子框时都需要将row和col数组进行清零操作。 
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
	//如果上面都正确，则返回true
	return true; 
}
