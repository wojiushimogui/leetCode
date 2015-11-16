#include<stdio.h>
#include<stdlib.h>

int countPrimes(int n) {
	if(n<=2){
		return 0;
	}
	bool *arr=(bool *)malloc(n*sizeof(bool));
	if(arr==NULL){
		exit(EXIT_FAILURE);
	}
	memset(arr,false,n*sizeof(bool));
	for(int i=2;i*i<n;i++){//依次将i=2，3，4,5，。。。的倍数全部设为true。最后剩下的就是素数 
		if(!arr[i]){
			for(int j=i;i*j<n;j++){
				arr[i*j]=true;
			}
		}
	}
	int count=0;
	for(int i=2;i<n;i++){//从2开始 
		if(!arr[i]){
			count++;
		}
	}
	
	return count; 


}


//思路：

 
