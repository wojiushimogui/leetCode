#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*
˼·������Ƚϼ򵥣������������н���ʱ�����������������ε������ȥ�������εĽ�����
�����������û�н�����������������ε����֮�͡� 
*/ 
int max(int a,int b){
	return a>b?a:b;
}
int min(int a,int b){
	return a<b?a:b;
}
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
	if(C<A||D<B||G<E||H<F){//������Ч�Լ�� 
		return 0;
	} 
	int twoRectArea=(C-A)*(D-B)+(G-E)*(H-F);
	int x0=max(A,E);
	int y0=max(B,F);
	int x1=min(C,G);
	int y1=min(D,H);
	int intersectArea=(x1-x0)*(y1-y0);	
	if(C<=E||D<=F||G<=A||H<=B){//û�н��� 
		return  twoRectArea;
	}	
	else{
		return twoRectArea-intersectArea; 
	}
    
}
