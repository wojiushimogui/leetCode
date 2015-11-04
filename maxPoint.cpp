

#include<stdio.h>
#include<stdlib.h>

int *arr; 
//返回a，b，c中的最大值。 
int max(int a,int b,int c){
	if(a>=b&&a>=c)
		return a;
	else if(b>=c)
		return b;
	else
		return c; 
}
//计算数组从下标index开始剩余元素的长度 
int sum(int index,int len){
	int sum=0;
	for(int i=index;i<len;i++){
		sum+=arr[i];
	}
	return sum;
}
//返回的是第二个人的得分。
//有个逻辑要清楚：第一次你是firstPoint，第二次你就是secondPoint，计算这两者的最大值才是你的得分。 
int maxPoint(int begin,int len){
	int length=len-begin;
	int firstPoint=0;//第一个选手先来 
	int secondPoint=0;
	//以下三个变量用来表示取一张牌、二张牌和三张牌的最大结果。 
	int onePoint=0;
	int twoPoint=0;
	int threePoint=0; 
	if(length<=3){
		//将剩余的全部取走，使其达到最大
		for(int i=begin;i<len;i++){
			firstPoint+=arr[i];
			return 0;
		} 
	}
	else if(length==4){
		firstPoint=arr[begin]+arr[begin+1]+arr[begin+2];
		secondPoint=arr[len-1];
		return secondPoint;
	}
	else{//还有很多元素
		onePoint=arr[begin]+maxPoint(begin+1,len);
		twoPoint=arr[begin]+arr[begin+1]+maxPoint(begin+2,len);
		threePoint=arr[begin]+arr[begin+1]+arr[begin+2]+maxPoint(begin+3,len);
		//在onePoint /twoPoint/threePoint 中取最大值
		firstPoint=max(onePoint,twoPoint,threePoint); 
		secondPoint=sum(begin,len)-firstPoint;
		return  secondPoint;
	}
	
}
int main(void){
	int k;
	while(scanf("%d",&k)!=EOF&&k>0){
		arr=(int *)malloc(k*sizeof(int));
		if(arr==NULL){
			exit(EXIT_FAILURE);
		}
		for(int i=0;i<k;i++)
			scanf("%d",arr+i);
		int result=sum(0,k)-maxPoint(0,k);//
		printf("%d\n",result);
	}
} 





