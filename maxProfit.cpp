#include<stdio.h>
#include<stdlib.h>

/*
只能买一次，卖一次，求最大利润 ；
思路：找出差值最大的两个值 ;时间复杂度为O(n^2),不能AC，报超时 
*/
int maxProfit(int* prices, int pricesSize) {
    if(prices==NULL||pricesSize<1){
    	return 0;
	} 
	int max= INT_MIN;
	for(int i=0;i<pricesSize;i++){		
		for(int j=i+1;j<pricesSize;j++){
			int dif=prices[j]-prices[i];
			if(dif>max){
				max=dif;
			}
		}
	}
	return max;
}
