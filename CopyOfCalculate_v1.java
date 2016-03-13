package com.wrh.leetcode;

import java.util.Stack;

public class CopyOfCalculate_v1 {
	
	public int calculate(String s) {
		if(s==null){
			return -1;
		}
		int len=s.length();
		char sign='+';
		Stack<Integer> stack=new Stack<Integer>();
		int num=0;
		for(int i=0;i<len;i++){
			char ch=s.charAt(i);
			if(Character.isDigit(ch)){//��ʱnum�����þ��ǵڶ���������
				num=ch-'0';
				while(i+1<len&&Character.isDigit(s.charAt(i+1))){
					num=num*10+s.charAt(i+1)-'0';
					i++;
				}
			}
			//��������һ��������󣬼�����˵ڶ���������֮��Ҫִ�к������㣬��ȡ����ǰһ��sign
			if(ch==' '){
				continue;
			}
			if(sign=='*'){
				stack.push(stack.pop()*num);
			}
			else if(sign=='/'){
				stack.push(stack.pop()/num);
			}
			//���¾�˵��ch�������֣�����ĳ�ַ���
			else if(sign=='+'){
				stack.push(num);
			}
			else if(sign=='-'){
				stack.push(-num);
			}			
			sign=ch;		
		}
		//��stack����������ͼ���
		int res=0;
		while(!stack.isEmpty()){
			res+=stack.pop();
		}
		return res;
	}
}
