


/*
丑数：利用递归来求解即可
下一个丑数一定是由前面的丑数乘以 2/3/5大于当前丑数且最小的那个。 
2015年11月13日19:18:39 
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//函数的功能：返回三个数中的最小值 
int my_min(int a,int b,int c){
	if(a<=b&&a<=c){
		return a;
	}
	else if(b<=c){
		return b;
	}
	else{
		return c;
	}
}
int nthUglyNumber(int n) {
    if(n<1){
    	return 0;
	}    
	//开辟n个空间来存储结果
	int *result=(int *)malloc(n*sizeof(int));
	if(result==NULL)
		exit(EXIT_FAILURE);
	memset(result,0,n*sizeof(int));
	result[0]=1;
	int cur=1;//用来指向当前result数组中即将保存 下一个丑数的位置 
	//三个指针，分别指向 下一个丑数的候选值的指针。 
	int *p2=result;
	int *p3=result;
	int *p5=result;
	while(n>1){
		int min=my_min((*p2)*2,(*p3)*3,(*p5)*5);
		
		result[cur]=min;
		cur++;
		while((*p2)*2<=min){
			p2++;
		}
		while((*p3)*3<=min){
			p3++;
		}
		while((*p5)*5<=min){
			p5++;
		}
		n--;
	}
	return result[cur-1]; 
	    
}

int main(void){
	int k;
	while(scanf("%d",&k)!=EOF){
		printf("%d\n",nthUglyNumber(k));
	}
}
