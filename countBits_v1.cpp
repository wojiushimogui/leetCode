#include<stdio.h>
#include<stdlib.h>
int mypow(int a,int b){
	int res=1;
	for(int i=0;i<b;i++){
		res*=a;
	}
	return res;
}

int* countBits(int num, int* returnSize) {
    if(num<0){
    	return NULL;
	}
	int *res=(int *)malloc((num+1)*sizeof(int));//注意：要开辟num+1个空间 
	if(res==NULL){
		printf("malloc failure");
		 
	}
	res[0]=0;
	*returnSize=num+1;
	if(num==0){
		return res;
	}
	res[1]=1;
	if(num==1){		
		return res;
	}
	//先找到离num最近且大于num的2的幂次 
	int n=num;
	int count=1;
	while(n!=1){
		n=n>>1;
		count++;
	} 	
	for(int i=1;i<count;i++){
		int powValue=mypow(2,i);
		for(int j=0;powValue+j<=num&&j<powValue;j++){//注意： powValue+j<=num
			res[powValue+j]=res[j]+1;
		}		
	}	
	return res;
}
int main(void){
	int n;
	while(true){
		scanf("%d",&n);
		int *returnSize=(int *)malloc(sizeof(int));
		if(returnSize==NULL){
			printf("malloc fail");
		}
		(*returnSize)=0;
		int* res=countBits(n, returnSize) ;
		for(int i=0;i<*returnSize;i++){
			printf("%d  ",res[i]);
		}
		printf("\n");
	}
}
