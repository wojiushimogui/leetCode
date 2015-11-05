//����������֪���ܲ��ܹ�����������Ҳ��������
//Ѱ�Ҹ��õķ��������ǰ���2Sum����
#include<stdio.h>
#include<stdlib.h>
#define N  4
int cmp(const void *a,const void *b){
	return (*((int *)a))-(*((int *)b));
}
int** fourSum(int* nums, int numsSize, int target, int* returnSize) {
    if(nums==NULL||numsSize<4){
    	return NULL;
	}
	int nn=(numsSize)*(numsSize-1)*(numsSize-2)*(numsSize-3)/24;//��������������� 
	int **result=(int **)malloc(nn*sizeof(int *));
	if(result==NULL)
		exit(EXIT_FAILURE);
	int index=0;
	//�Ƚ�������
	qsort(nums,numsSize,sizeof(nums[0]),cmp); 
	
	for(int i=0;i<numsSize-3;i++){
		for(int j=i+1;j<numsSize-2;j++){
			int begin=j+1;
			int end=numsSize-1;
			while(begin<end){
				int diff=nums[i]+nums[j]+nums[begin]+nums[end]-target;
				if(diff==0){
					//������ 
					//������Ƿ�������ظ��ġ�
					bool flag=true;//������ʶ�Ƿ�������ظ��� 
					for(int k=0;k<index;k++){
						if(result[k][0]==nums[i]&&result[k][1]==nums[j]&&result[k][2]==nums[begin]&&result[k][3]==nums[end]){
							flag=false;
							begin++;//����Ҫע�⣬Ҫ���м� 1������ 
							break;
						}
					} 
					if(flag){
						result[index]=(int *)malloc(N*sizeof(int));
						if(result[index]==NULL)
							exit(EXIT_FAILURE);
						result[index][0]=nums[i];
						result[index][1]=nums[j];
						result[index][2]=nums[begin];
						result[index][3]=nums[end];
						index++;
						begin++;
					}
					
				}
				else if(diff<0){
					begin++;
				} 
				else{
					end--;
				}
			}
			
		}
	}
	*returnSize=index;
	return result;
}

int main(void){
	int n;
	int target;
	while(scanf("%d %d",&n,&target)!=EOF&&n>=4){
		int *arr=(int *)malloc(n*sizeof(int ));
		if(arr==NULL){
			exit(EXIT_FAILURE);
		}
		for(int i=0;i<n;i++){
			scanf("%d",arr+i);
		}
		int returnSize=0;
		int **result=fourSum(arr,n,target,&returnSize);
		for(int i=0;i<returnSize;i++){
			int *temp=(result[i]);
			for(int j=0;j<N;j++){
				printf("%d   ",temp[j]);
			}
			printf("\n");
		}
		
		for(int i=0;i<returnSize;i++){
			free(result[i]);
			result[i]=NULL;
		}
		
	}
	return 0;
}
