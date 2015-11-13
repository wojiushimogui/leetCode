
#include<stdio.h>
#include<stdlib.h>

bool isUgly(int num) {
    if(num<1){
        return false;
    }
    if(num==1){
        return true;
    }
    int count=32;//如果是一个丑数，while循环内部的代码最多执行32次。 
    while(count>0&&num!=1){
        if(num%2==0){
            num=num/2;
        }
        if(num%3==0){
            num/=3;
        }
        if(num%5==0){
            num/=5;
        }
        count--;
    }
    if(num==1){//如果是一个丑数，则进行上面的运算后，num将会变为1 
        return true;
    }
    return false;
    
}

int main(void){
	int k;
	while(scanf("%d",&k)!=EOF){
		if(isUgly(k)){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
} 
