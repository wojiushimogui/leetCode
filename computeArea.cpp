#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*
思路：此题比较简单，当两个矩形有交集时，则结果就是两个矩形的面积减去两个矩形的交集。
如果两个矩形没有交集，则就是两个矩形的面积之和。 
*/ 
int max(int a,int b){
	return a>b?a:b;
}
int min(int a,int b){
	return a<b?a:b;
}
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
	if(C<A||D<B||G<E||H<F){//矩形有效性检查 
		return 0;
	} 
	int twoRectArea=(C-A)*(D-B)+(G-E)*(H-F);
	int x0=max(A,E);
	int y0=max(B,F);
	int x1=min(C,G);
	int y1=min(D,H);
	int intersectArea=(x1-x0)*(y1-y0);	
	if(C<=E||D<=F||G<=A||H<=B){//没有交集 
		return  twoRectArea;
	}	
	else{
		return twoRectArea-intersectArea; 
	}
    
}
