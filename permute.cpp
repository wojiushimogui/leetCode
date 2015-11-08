
#include<stdio.h>
#include<stdlib.h>

/*
��һ�������ȫ���� 
���õݹ�������
*/
int **result; 
int index_my=0;
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
int **my_premute(int *nums,int k,int length){
	if(nums==NULL||length<1){
		return NULL;
	}
	if(k==length){//���е�һ�����������
		 result[index_my]=(int *)malloc(length*sizeof(int));
		 if(result[index_my]==NULL){
		 	exit(EXIT_FAILURE);
		 }
		 for(int i=0;i<length;i++){
		 	result[index_my][i]=nums[i];
		 }
		 index_my++;
	}
	else{
		for(int i=k;i<length;i++){			
				swap(&nums[i],&nums[k]);//�����k��Ԫ�ؽ��н�����Ȼ�������һ�ֵĵݹ顣 
				my_premute(nums,k+1,length);
				swap(&nums[i],&nums[k]);
			}
		}
}
int** permute(int* nums, int numsSize, int* returnSize) {
    if(nums==NULL||numsSize<1){
    	return NULL;
	} 
	int num=1;
	for(int i=1;i<=numsSize;i++){
		num*=i;
	}
	index=0;
	result=(int **)malloc(num*sizeof(int *));
	if(result==NULL){
		printf("malloc fail");
		exit(EXIT_FAILURE);
	}
	
	my_premute(nums,0,numsSize);
	*returnSize=index_my;
	return result;
	
}

int main(void){
	int k;
	while(scanf("%d",&k)!=EOF){
		int *arr=(int *)malloc(k*sizeof(int));
		if(arr==NULL){
			exit(EXIT_FAILURE);
		}
		for(int i=0;i<k;i++){
			scanf("%d",arr+i);
		}
		int returnSize=0;
		int **temp=permute(arr,k,&returnSize);
		for(int i=0;i<returnSize;i++){
			for(int j=0;j<k;j++){
				printf("%d  ",temp[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
}
