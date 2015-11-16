#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
˼·��
һ������װˮֻ���������߶�����͵ĸ߶���Ϊ�����ĸ߶ȡ�
������Ǵ������������Զ�ĳ���(����һ�������һ��Ԫ��),��ô��������Ⱦ��Ρ�
����,���ǿ��԰ᵽ���̵Ŀ�ȵ��Ǹ߶�ֻ����������������� 
���ڣ����ǿ����ƶ��߶Ƚ�С���Ǹ��߶ȣ������ٿ�ȣ����Ǹ߶ȿ������ӣ��������������Ҳ�����ӣ�������ȡ��������� 
*/

int min(int a,int b){
	return a<=b?a:b;
}
int maxArea(int* height, int heightSize) {
    if(height==NULL||heightSize<1){
    	return 0;
	} 
	int max=0;
	int begin=0;
	int end=heightSize-1;
	while(begin<end){
		int area=min(height[begin],height[end])*(end-begin);
		if(area>max){
				max=area;
		}
		if(height[begin]>height[end]){
			end--;
		}
		else if(height[begin]<=height[end]){
			begin++;
		}
	} 
	
	return max;
}

int main(void){
	int n;
	while(scanf("%d",&n)!=EOF&&n>0){
		int *arr=(int *)malloc(n*sizeof(int));
		if(arr==NULL){
			exit(EXIT_FAILURE); 
		}
		for(int i=0;i<n;i++){
			scanf("%d",arr+i);
		}
		int result=maxArea(arr,n);
		printf("%d\n",result);
	}
	return 0;
} 
