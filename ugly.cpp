


/*
���������õݹ�����⼴��
��һ������һ������ǰ��ĳ������� 2/3/5���ڵ�ǰ��������С���Ǹ��� 
2015��11��13��19:18:39 
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//�����Ĺ��ܣ������������е���Сֵ 
int my_min(int a,int b,int c){
	if(a<=b&&a<=c){
		return a;
	}
	else if(b<=c){
		return b;
	}
	else{
		return c;
	}
}
int nthUglyNumber(int n) {
    if(n<1){
    	return 0;
	}    
	//����n���ռ����洢���
	int *result=(int *)malloc(n*sizeof(int));
	if(result==NULL)
		exit(EXIT_FAILURE);
	memset(result,0,n*sizeof(int));
	result[0]=1;
	int cur=1;//����ָ��ǰresult�����м������� ��һ��������λ�� 
	//����ָ�룬�ֱ�ָ�� ��һ�������ĺ�ѡֵ��ָ�롣 
	int *p2=result;
	int *p3=result;
	int *p5=result;
	while(n>1){
		int min=my_min((*p2)*2,(*p3)*3,(*p5)*5);
		
		result[cur]=min;
		cur++;
		while((*p2)*2<=min){
			p2++;
		}
		while((*p3)*3<=min){
			p3++;
		}
		while((*p5)*5<=min){
			p5++;
		}
		n--;
	}
	return result[cur-1]; 
	    
}

int main(void){
	int k;
	while(scanf("%d",&k)!=EOF){
		printf("%d\n",nthUglyNumber(k));
	}
}
