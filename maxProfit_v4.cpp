#include<stdio.h>
#include<stdlib.h>
#include<Math.h> 
/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.
*/
/*
思路：分而治之，将prices分成两个部分，分别求这两部分的最大值 
解释：
首先，因为能买2次（第一次的卖可以和第二次的买在同一时间），但第二次的买不能在第一次的卖左边。
所以维护2个表，f1和f2，size都和prices一样大。
意义：
f1[i]表示 -- 截止到i下标为止，左边所做交易能够达到最大profit；
f2[i]表示 -- 从i下标开始，右边所做交易能够达到最大profit；
那么，对于f1 + f2，寻求最大即可。
*/

int max(int a,int b){
	return (a>b)?a:b;
}
int min(int a,int b){
	return (a<b)?a:b;
}
int maxProfit(int* prices, int pricesSize) {
    if(prices==NULL||pricesSize<1){
    	return 0;
	}
	
	int *f1=(int *)malloc(pricesSize*sizeof(int));
	int *f2=(int *)malloc(pricesSize*sizeof(int)); 
	if(f1==NULL||f2==NULL){
		exit(EXIT_FAILURE);
	}
	//先看第一个交易
	f1[0]=0;
	int buyPriceMin=prices[0];
	for(int i=1;i<pricesSize;i++){
		buyPriceMin=min(buyPriceMin,prices[i]);
		f1[i]=max(f1[i-1],prices[i]-buyPriceMin);
//		if(prices[i]<buyPriceMin){
//			buyPriceMin=prices[i];
//		}
//		else{
//			int profit=prices[i]-buyPriceMin;
//			f1[i]=max(f1[i-1],profit);
//		}
	}
	//再看第二个交易，从右到左,寻找交易利润最大 
	f2[pricesSize-1]=0;
	int SellPriceMax=prices[pricesSize-1];
	for(int i=pricesSize-2;i>=0;i--){
		SellPriceMax=max(SellPriceMax,prices[i]);
		f2[i]=max(f2[i+1],SellPriceMax-prices[i]);
//		if(SellPriceMax<prices[i]){
//			SellPriceMax=prices[i];
//		}
//		else{
//			int profit=SellPriceMax-prices[i];
//			f2[i]=max(f2[i+1],profit);
//		}
	}
	//在f1+f2中寻找的最大值就是最大利润值
	int maxProfit=0;
	for(int i=0;i<pricesSize;i++){
		maxProfit=max(maxProfit,f1[i]+f2[i]);
	} 
	return maxProfit;
}
