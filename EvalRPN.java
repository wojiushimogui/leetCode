package com.wrh.leetcode;

import java.util.Stack;

public class EvalRPN {
	
	 public int evalRPN(String[] tokens) {
		 	if(tokens==null){
		 		return 0;
		 	}
		 	Stack<Integer> s=new Stack<Integer>();
		 	for(int i=0;i<tokens.length;i++){
		 		switch(tokens[i]){
		 			case "+":
		 				s.push(s.pop()+s.pop());
		 				break;
		 			case "-"://注意
		 				int firstValue=s.pop();
		 				int secondValue=s.pop();
		 				s.push(secondValue-firstValue);
		 				break;
		 			case "*":
		 				s.push(s.pop()*s.pop());
		 				break;
		 			case "/"://注意：这里不能写：s.push(s.pop()/s.pop());
		 				int firstValue1=s.pop();
		 				int secondValue1=s.pop();
		 				s.push(secondValue1/firstValue1);
		 				break;
		 			default:
		 				s.push(Integer.parseInt(tokens[i]));		 					
		 		}
		 	}
		 return s.pop();
	   }
}
