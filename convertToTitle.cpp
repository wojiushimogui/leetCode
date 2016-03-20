#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#define N  100
void swap(char *a,char *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
char* convertToTitle(int n) {
    if(n<1){
    	return NULL;
	}
	char *res=(char *)malloc(N*sizeof(char));
	if(res==NULL){
		exit(EXIT_FAILURE);
	} 
	int index=0;
	while(n){
		int temp=n%26;	
		if(temp==0){//注意：要对26 的整倍数做一点特殊处理 
			res[index++]='Z';
			n=(n/26)-1;
		}
		else{
			res[index++]='A'+temp-1;
			n=n/26;	
		}							
	}
	//将res翻转就是最后的结果
	int begin=0;
	int end=index-1;
	while(begin<end){
		swap(res+begin,res+end);
		begin++;
		end--;
	} 
	res[index]='\0';
	return res;
}
