package com.wrh.leetcode;

import java.util.Stack;

public class Calculate {
	public static int calculate(String s) {
		if(s==null){
			return -1;
		}
		int len=s.length();
		int sign=1;//1:+,-1:-;
		int result=0;
		Stack<Integer> stack=new Stack<Integer>();//������������ʱ���ͽ�֮ǰ�Ľ����ջ
		for(int i=0;i<len;i++){
			char ch=s.charAt(i);
			if(Character.isDigit(ch)){
				int num=ch-'0';
				while(i+1<len&&Character.isDigit(s.charAt(i+1))){
					num=num*10+s.charAt(i+1)-'0';
					i++;
				}
				result+=num*sign;
			}
			else if(ch=='+'){
				sign=1;
			}
			else if(ch=='-'){
				sign=-1;
			}
			else if(ch==' '){
				continue;
			}
			else if(ch=='('){//��ջ��������
				stack.push(result);
				stack.push(sign);
				result=0;
				sign=1;
			}
			else if(ch==')'){//ע�⣺�Ⱥ�˳��
				int signInStack=stack.pop();
				int tempRes=stack.pop();
				tempRes+=result*signInStack;
				result=tempRes;
			}
		}
		return result;
	}
}
