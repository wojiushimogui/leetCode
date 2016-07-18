package com.wrh.leetcode;

import java.util.Arrays;

public class NumSquares {

    public int numSquares(int n) {
    	int[] dp=new int[n+1];
    	Arrays.fill(dp, Integer.MAX_VALUE);
    	//将所有平方和的结果置为1
    	for(int i=0;i*i<=n;i++){
    		dp[i*i]=1;
    	}
    	/*
    	 * 如果一个数x可以表示为一个任意数a加上一个平方数bｘb，也就是x=a+bｘb，那么能组成这个数x最少的平方数个数，
    	 * 就是能组成a最少的平方数个数加上1（因为b*b已经是平方数了）。
    	 * */
    	for(int a=0;a<n;a++){
    		for(int b=0;a+b*b<=n;b++){
    			dp[a+b*b]=Math.min(dp[a]+1, dp[a+b*b]);
    		}
    	}
    	return dp[n];
	}
	
	public static void main(String[] args){
		int n = 12;
		int res = new NumSquares().numSquares(n);
		System.out.println(res);
		
	}
}
