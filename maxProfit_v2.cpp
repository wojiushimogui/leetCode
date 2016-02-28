#include<stdio.h>
#include<stdlib.h>
/*
贪婪算法 :判断相邻的两个元素是否是大于零，如果大于零，则可以构成一次交易
如果相邻的两个元素之差小于零，则可以理解为当天买当天卖，利润为零。综上所述：统计所有相邻的元素大于零的之和即为最大收益 
*/
int maxProfit(int* prices, int pricesSize) {
    if(prices==NULL||pricesSize<1){
    	return 0;
	}
	int profit=0;
	for(int i=1;i<pricesSize;i++){
		profit+=(prices[i]-prices[i-1])>0?(prices[i]-prices[i-1]):0;
	}
	return profit;	
}
