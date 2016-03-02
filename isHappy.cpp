#include<stdio.h>
#include<stdlib.h>
//�����Ĺ��ܣ������ָ�λ����ĺ� 
int everyDigitSquareSum(int n){
	if(n<0){
		return 0;
	} 
	int sum=0;
	while(n){
		int remainder=n%10;
		sum+=(remainder*remainder);
		n/=10;
	}
	return sum;
}
#define N 10000
//�����Ĺ��ܣ�����������Ƿ����target����� 
bool isExist(int *nums,int numsSize,int target){
	if(nums==NULL||numsSize<1){
		return false;
	} 
	for(int i=0;i<numsSize;i++){
		if(nums[i]==target){
			return true;
		}
	}
	return false;
}
bool isHappy(int n) {
    if(n<0){
    	return 0;
	}
	int *value=(int *)malloc(N*sizeof(int));
	if(value==NULL){
		exit(EXIT_FAILURE);
	}
	int index=0;
	while(n!=1){
		value[index++]=n;
		int res=everyDigitSquareSum(n);		
		if(isExist(value,index,res)){//�����ѭ��������false 
			return false;
		}
		n=res;
	}
	return true;
}

int main(void){
	int n;
	scanf("%d",&n);
	bool res=isHappy( n);
	if(res){
		printf("is a happy number\n");
	}
	else{
		printf("NO\n");
	}
}
