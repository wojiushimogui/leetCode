#include<stdio.h>
#include<stdlib.h>

/*
ֻ����һ�Σ���һ�Σ���������� ��
˼·���ҳ���ֵ��������ֵ ;ʱ�临�Ӷ�ΪO(n^2),����AC������ʱ 
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
