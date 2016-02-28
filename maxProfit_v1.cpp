#include<stdio.h>
#include<stdlib.h>

/*
只能买一次，卖一次，求最大利润 ；
思路：找出差值最大的两个值 
*/

int maxProfit(int* prices, int pricesSize) {
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
			int dif=prices[i]-buyPrice;
			max=(max>dif)?max:dif;
		}
	}
	return max;
}
