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
			if(Character.isDigit(ch)){//此时num的作用就是第二个操作数
				num=ch-'0';
				while(i+1<len&&Character.isDigit(s.charAt(i+1))){
					num=num*10+s.charAt(i+1)-'0';
					i++;
				}
			}
			//但碰到下一个运算符后，即获得了第二个操作数之后，要执行何种运算，就取决于前一个sign
			if(ch==' '){
				continue;
			}
			if(sign=='*'){
				stack.push(stack.pop()*num);
			}
			else if(sign=='/'){
				stack.push(stack.pop()/num);
			}
			//以下就说明ch不是数字，而是某种符号
			else if(sign=='+'){
				stack.push(num);
			}
			else if(sign=='-'){
				stack.push(-num);
			}			
			sign=ch;		
		}
		//将stack中所有树求和即可
		int res=0;
		while(!stack.isEmpty()){
			res+=stack.pop();
		}
		return res;
	}
}
