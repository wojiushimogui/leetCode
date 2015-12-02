package com.wrh.leetcode;
/*
 * 此题完成的功能是，在二维字符数组board中是否存在字符串word，这里的字符串word由board相邻的字符构成。
 * 注：这里的相邻是“上下左右”相邻都可以。
 * */
public class Solution_8 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}
	//函数的功能，检查从矩阵board的位置x,y处是否有满足从start下标开始的word
	public boolean exist(char[][]board,int x,int y,String word,int start){
		if(start>=word.length()) return true;//这种情况，说明找到了符合word的单词
		if(x<0||x>board.length||y<0||y>board[0].length) return false;
		if(board[x][y]==word.charAt(start++)){//先满足第start个字符，才开始检查start后面的字符，
			
			char temp=board[x][y];
			board[x][y]='#';//用一个特殊的字符来标记已经遍历过的位置
			//检查范围为，（x,y）的上下左右
			boolean res=exist(board,x-1,y,word,start)||exist(board,x+1,y,word,start)||exist(board,x,y-1,word,start)||exist(board,x,y+1,word,start);
			board[x][y]=temp;
			return res;
		}
		return false;
	}
	public boolean exist(char[][] board, String word) {
        if(board==null||board.length<1){
        	return false;
        }
        int len=board.length;
        for(int i=0;i<len;i++){
        	for(int j=0;j<board[0].length;j++){
        		if(exist(board,i,j,word,0)) return true;
        	}
        }
		return false;
    }

}
