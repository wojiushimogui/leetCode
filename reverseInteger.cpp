/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int reverse(int x) {
//	int intLen=sizeof(int)*8;
//	if(x>pow(2,intLen-1)-1||x<-pow(2,intLen-1)){
//		return 0;
//	}
	 
    long result=0;
    int symbol=1;
    if(x<0){
    	x=-x;
    	symbol=-1;
	}
    
    while(x!=0){
    	int temp=x%10;
    	x/=10;
    	result=result*10+temp;
    	 
	}
	//判断下result是否只在低32为有数字，高位为0
	if(result>>31){
		return 0;
	}
	else{
		return (int)(symbol*result);
	} 
	
}

int main(void){
	int num;
	while(scanf("%d",&num)!=EOF){
		int result=reverse(num);
		printf("%d\n",result);
	}
	return 0;
}
