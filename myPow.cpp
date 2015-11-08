
#include<stdio.h>
#include<stdlib.h> 
double myPow(double x, int n) {
    int symbol=1;//用来标识n是不是为正数
    if(n==0){
        return 1;
    }
//    if(n==1){
//        return x;
//    }
    if(n<0){//保证n为正数
        n=-n;
        symbol=-1;
    }
    
    
    if(n%2==0){
       return symbol==1?myPow(x*x,n/2):(1/(myPow(x*x,n/2)));
    }
    else {
        return symbol==1?(x*myPow(x*x,n/2)):(1/(x*myPow(x*x,n/2)));
    }
    
}
int main(void){
	double x;
	int n;
	while(scanf("%lf %d",&x,&n)!=EOF){
		printf("%lf\n",myPow(x,n));
	}
	return 0;
}
