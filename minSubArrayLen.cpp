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
			//开始从左往右逐一去掉
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
			count--;	//由于此时begin++，导致现在的sum只有count-1个数构成	
		}					
	}
	if(minCount==INT_MAX&&count==numsSize){//所有数的和均小于sum 
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
