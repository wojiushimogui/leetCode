package com.wrh.leetcode;

import java.util.Arrays;

public class NumSquares {

    public int numSquares(int n) {
    	int[] dp=new int[n+1];
    	Arrays.fill(dp, Integer.MAX_VALUE);
    	//������ƽ���͵Ľ����Ϊ1
    	for(int i=0;i*i<=n;i++){
    		dp[i*i]=1;
    	}
    	/*
    	 * ���һ����x���Ա�ʾΪһ��������a����һ��ƽ����b��b��Ҳ����x=a+b��b����ô����������x���ٵ�ƽ����������
    	 * ���������a���ٵ�ƽ������������1����Ϊb*b�Ѿ���ƽ�����ˣ���
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
