#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
˼·���õݹ�����⼴��
һ�����·�����������ұ߽ڵ��·������+���·��ڵ��·������ 
*/
int uniquePaths(int m, int n) {
	if(m==1&&n==1){
		return 0;
	}
    if(m==1||n==1){
    	return 1;
	}
	return uniquePaths(m,n-1)+uniquePaths(m-1,n); 
}
int main(void){
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF){
		int result=uniquePaths(m,n);
		printf("%d \n",result);
	}
	return 0;
}
