#include<stdio.h>
#include<stdlib.h>
//函数的功能：求数字各位上面的和 
int everyDigitSquareSum(int n){
	if(n<0){
		return 0;
	} 
	int sum=0;
	while(n){
		int remainder=n%10;
		sum+=(remainder*remainder);
		n/=10;
	}
	return sum;
}

int addDigits(int num) {
    if(num<0){
    	return 0;
	}
	while(!(0<num&&num<=9)){
		num=everyDigitSquareSum(num);
	}
	return num;
}
