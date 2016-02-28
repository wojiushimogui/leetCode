#include<stdio.h>
#include<stdlib.h>
/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.
*/
/*
思路：分而治之，将prices分成两个部分，分别求这两部分的最大值 
*/
int getMaxProfitOneTransactions(int* prices, int pricesSize){
	if(prices==NULL||pricesSize<1){
		return 0;
	}
	int max=0;
	int buyPrice=prices[0];
	for(int i=0;i<pricesSize;i++){
		if(prices[i]<buyPrice){
			buyPrice=prices[i];
		}
		else{
			int profit=prices[i]-buyPrice;
			max=(max>profit)?max:profit;
		}
	}
	return max;	
}
int maxProfit(int* prices, int pricesSize) {
    if(prices==NULL||pricesSize<1){
    	return 0;
	}
	int max=0;
	for(int i=0;i<pricesSize;i++){
		int maxPartOne_Two=getMaxProfitOneTransactions(prices,i)+getMaxProfitOneTransactions(prices+i,pricesSize-i);
		if(maxPartOne_Two>max){
			max=maxPartOne_Two;
		}
	}
	return max;
}
