#include<stdio.h>
#include<stdlib.h>

/*
ֻ����һ�Σ���һ�Σ���������� ��
˼·���ҳ���ֵ��������ֵ 
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
