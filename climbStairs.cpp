#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
����DP�ķ�����һ��̨�׵ķ�������Ϊ1�Σ�����̨�׵ķ�������Ϊ2����
n��̨�׵ķ�������������n-2��̨�ף�Ȼ��2��ֱ�������һ����������n-1��̨�ף��ٵ�����һ����
��ʽ��S[n] = S[n-1] + S[n-2] S[1] = 1 S[2] = 2
*/
int climbStairs(int n) {
    if(n<1){
        return 0;
    }
    int *result=(int *)malloc(n*sizeof(int));
    if(result==NULL){
    	exit(EXIT_FAILURE);
	}
	if(n==1||n==2){
		return n;
	}
	result[0]=1;
	result[1]=2;
    for(int i=2;i<n;i++){
        //��S[n] = S[n-1] + S[n-2] S[1] = 1 S[2] = 2
        result[i]=result[i-1]+result[i-2];
        
    }
    return result[n-1];
}
int main(void){
	int n;
	while(scanf("%d",&n)!=EOF){
		int result=climbStairs(n);
		printf("%d\n",result);
		
	}
} 
