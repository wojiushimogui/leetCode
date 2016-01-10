#include<stdio.h>
#include<stdlib.h>
//ͳ��1~n����ɵ�Ψһ�����������ĸ��� 
//����������������Ϊ�������������Ϊ�գ����������ڵ��ֵȫ��С�ڸ��ڵ㣬�����������Ϊ�գ���������ȫ�����ڸ��ڵ��ֵ
//�ο���ַ��https://leetcode.com/discuss/75282/easy-to-understand-top-down-dp-solution 
/*
For a valid BST, there must be a node that is the root. The root can be any number between 1 and n. What if the root is k where k is in between 1 and n? It becomes obvious that 1 to k-1 should be k's left children and k+1 to n should be k's right children. Thus, a recursive formula is formulated as follows:

result of BSTs with k being the root 
= count of BSTs of k-1 consecutive numbers * count of BSTs of n-k consecutive numbers
And since we have a total of n choices for k, total number of BSTs is thus a sum of all n choices for k.
*/ 
int numTreeWhenRootCountEqualN(int n,int *resCountwhenRootValue_N){
	if(n<=1){
		return 1;
	}
	if(resCountwhenRootValue_N[n-1]>0){
		return resCountwhenRootValue_N[n-1];
	}
	int totalCount=0;
	for(int i=1;i<=n;i++){//ͳ�Ƶ����ڵ�Ϊ1~nʱ�Ķ����������ĸ��� 
		// numTreeWhenRootCountEqualN(i-1,resCountwhenRootValue_N)Ϊ�����ڵ�Ϊiʱ�������������������ĸ���
		// numTreeWhenRootCountEqualN(n-i,resCountwhenRootValue_N)�����ڵ�Ϊiʱ�������������������ĸ���
		totalCount+=numTreeWhenRootCountEqualN(i-1,resCountwhenRootValue_N)*numTreeWhenRootCountEqualN(n-i,resCountwhenRootValue_N);		
	}
	resCountwhenRootValue_N[n-1]=totalCount;//���渴�� 
	return totalCount; 
}
int numTrees(int n) {
	if(n<1) return 0;
	//����һ�οռ䣬���������������� resCountwhenRootValue_N[k]�б����ŵ��Ǹ��ڵ����ֵΪ k-1ʱ���������Ķ����������ĸ��� 
    int *resCountwhenRootValue_N=(int *)malloc(n*sizeof(int));
	if(resCountwhenRootValue_N==NULL){
		exit(EXIT_FAILURE);
	} 
	//��ʼ��Ϊ��
	memset(resCountwhenRootValue_N,0,n*sizeof(int));
	return numTreeWhenRootCountEqualN(n,resCountwhenRootValue_N); 
}
