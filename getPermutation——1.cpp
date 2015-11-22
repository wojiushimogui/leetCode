

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* getPermutation(int n, int k) {
    if(n<1||k<1){
		return NULL; 
	}
	//开辟一段空间来保存结果 
	char* result=(char *)malloc((n+1)*sizeof(char));
	if(result==NULL){
		exit(EXIT_FAILURE);
	}
	//开辟一段空间，来保存1~n的字符 
	char *s=(char *)malloc((n)*sizeof(char));
	if(s==NULL){
		exit(EXIT_FAILURE);
	} 
	int count=1; //用来表示n！ 
	for(int i=0;i<n;i++){
		s[i]=(char)(i+'1');
		count*=(i+1);
	}
	//求结果中每一位对应的字符 
	k--;//减一的原因在于：第（n-1）!个排列应该是以1开头的最后一个排列；如果不减一，将会是以2开头的第一个 
	for(int i=0;i<n;i++){
		count=count/(n-i);
		int index=k/count;
		result[i]=s[index];
		for(int j=index;j<n-i-1;j++){//将s后面的元素提前 
			s[j]=s[j+1];
		}
		//更新k
		k=k%count; 
		
	} 
	result[n]='\0';
	return result;
}

int main(void){
	
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF&&n>0&&k>0){
		char *result=getPermutation(n,k);
		
		puts(result);
	}
	return 0;
}
