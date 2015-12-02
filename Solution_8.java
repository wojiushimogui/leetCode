package com.wrh.leetcode;
/*
 * ������ɵĹ����ǣ��ڶ�ά�ַ�����board���Ƿ�����ַ���word��������ַ���word��board���ڵ��ַ����ɡ�
 * ע������������ǡ��������ҡ����ڶ����ԡ�
 * */
public class Solution_8 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}
	//�����Ĺ��ܣ����Ӿ���board��λ��x,y���Ƿ��������start�±꿪ʼ��word
	public boolean exist(char[][]board,int x,int y,String word,int start){
		if(start>=word.length()) return true;//���������˵���ҵ��˷���word�ĵ���
		if(x<0||x>board.length||y<0||y>board[0].length) return false;
		if(board[x][y]==word.charAt(start++)){//�������start���ַ����ſ�ʼ���start������ַ���
			
			char temp=board[x][y];
			board[x][y]='#';//��һ��������ַ�������Ѿ���������λ��
			//��鷶ΧΪ����x,y������������
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
