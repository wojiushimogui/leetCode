#include<stdio.h>
#include<stdlib.h>
#include<Math.h> 
/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.
*/
/*
˼·���ֶ���֮����prices�ֳ��������֣��ֱ����������ֵ����ֵ 
���ͣ�
���ȣ���Ϊ����2�Σ���һ�ε������Ժ͵ڶ��ε�����ͬһʱ�䣩�����ڶ��ε������ڵ�һ�ε�����ߡ�
����ά��2����f1��f2��size����pricesһ����
���壺
f1[i]��ʾ -- ��ֹ��i�±�Ϊֹ��������������ܹ��ﵽ���profit��
f2[i]��ʾ -- ��i�±꿪ʼ���ұ����������ܹ��ﵽ���profit��
��ô������f1 + f2��Ѱ����󼴿ɡ�
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
	//�ȿ���һ������
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
	//�ٿ��ڶ������ף����ҵ���,Ѱ�ҽ���������� 
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
	//��f1+f2��Ѱ�ҵ����ֵ�����������ֵ
	int maxProfit=0;
	for(int i=0;i<pricesSize;i++){
		maxProfit=max(maxProfit,f1[i]+f2[i]);
	} 
	return maxProfit;
}
