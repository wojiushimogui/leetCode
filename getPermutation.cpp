
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
思路：递归法，要注意的是：结果是排序后的第k个结果 
*/
void swap(char *a,char *b){
	char temp=*a;
	*a=*b;
	*b=temp;
}
void bubbleSort(char *arr,int begin,int length){
    int i,j;
    for(i=begin;i<length;i++){
        for(j=i+1;j<length;j++){
            if(arr[i]>arr[j]){
                swap(&arr[i],&arr[j]);
            }
        }
    }
}
bool flag=true;
char *result;
void getPermutate(char *arr,int len,int* k,int start){
	if(arr==NULL||len<0){
		return ;
	}
	if(start==len-1){//得到一种结果
		if((*k)==1){//得到最终的结果 
			flag=false;
			for(int k=0;k<len;k++){
				result[k]=arr[k];
			}
			result[len]='\0';
			
		} 
		(*k)--;			
	}
	else{
		for(int i=start;i<len;i++){
			if(flag){
				swap(&arr[start],&arr[i]);
				bubbleSort(arr,start+1,len);
				getPermutate(arr,len,k,start+1);
				if(flag){
					bubbleSort(arr,start+1,len);
				}
				
			}
		} 
	}
	
}
char* getPermutation(int n, int k) {
    if(n<1||k<1){
		return NULL; 
	}
	flag=true;
	//开辟一段空间来保存结果 
	result=(char *)malloc((n+1)*sizeof(char));
	if(result==NULL){
		exit(EXIT_FAILURE);
	} 
	char *s=(char *)malloc((n)*sizeof(char));
	if(s==NULL){
		exit(EXIT_FAILURE);
	} 
	for(int i=0;i<n;i++){
		s[i]=(char)(i+'1');
	//	printf("%c   ",s[i]);
	}
	getPermutate(s,n,&k,0) ;
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
