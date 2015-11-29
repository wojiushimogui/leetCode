#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
利用DP的方法，一个台阶的方法次数为1次，两个台阶的方法次数为2个。
n个台阶的方法可以理解成上n-2个台阶，然后2步直接上最后一步；或者上n-1个台阶，再单独上一步。
公式是S[n] = S[n-1] + S[n-2] S[1] = 1 S[2] = 2
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
        //当S[n] = S[n-1] + S[n-2] S[1] = 1 S[2] = 2
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
