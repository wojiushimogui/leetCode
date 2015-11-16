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
	for(int i=2;i*i<n;i++){//���ν�i=2��3��4,5���������ı���ȫ����Ϊtrue�����ʣ�µľ������� 
		if(!arr[i]){
			for(int j=i;i*j<n;j++){
				arr[i*j]=true;
			}
		}
	}
	int count=0;
	for(int i=2;i<n;i++){//��2��ʼ 
		if(!arr[i]){
			count++;
		}
	}
	
	return count; 


}


//˼·��

 
