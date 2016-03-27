#include<stdio.h>
#include<stdlib.h>

int minSubArrayLen(int s, int* nums, int numsSize) {
    if(s<=0||nums==NULL||numsSize<1){
    	return 0;
	}
	int sum=0;
	int count=0;
	int begin=0;
	int minCount=INT_MAX;
	for(int i=0;i<numsSize;i++){
		count++;
		sum+=nums[i];
		if(sum>=s){
			//��ʼ����������һȥ��
			while(sum>=s){
				sum-=nums[begin];
				begin++;
				if(sum>=s){
					count--;					
				}
				if(count<minCount){
					minCount=count;
				}								
			}			 
			count--;	//���ڴ�ʱbegin++���������ڵ�sumֻ��count-1��������	
		}					
	}
	if(minCount==INT_MAX&&count==numsSize){//�������ĺ;�С��sum 
		return 0;
	}
	else{
		return minCount;
	}
	
}

int main(void){
	int len;
	int s;
	int arr[len];
	while(scanf("%d %d",&len,&s)!=EOF){
		for(int i=0;i<len;i++){
			scanf("%d",arr+i);
		}
		int res=minSubArrayLen(s,arr,len);
		printf("%d \n",res);
	}
	return 0;
}
