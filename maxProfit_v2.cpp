#include<stdio.h>
#include<stdlib.h>
/*
̰���㷨 :�ж����ڵ�����Ԫ���Ƿ��Ǵ����㣬��������㣬����Թ���һ�ν���
������ڵ�����Ԫ��֮��С���㣬��������Ϊ����������������Ϊ�㡣����������ͳ���������ڵ�Ԫ�ش������֮�ͼ�Ϊ������� 
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
