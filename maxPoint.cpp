

#include<stdio.h>
#include<stdlib.h>

int *arr; 
//����a��b��c�е����ֵ�� 
int max(int a,int b,int c){
	if(a>=b&&a>=c)
		return a;
	else if(b>=c)
		return b;
	else
		return c; 
}
//����������±�index��ʼʣ��Ԫ�صĳ��� 
int sum(int index,int len){
	int sum=0;
	for(int i=index;i<len;i++){
		sum+=arr[i];
	}
	return sum;
}
//���ص��ǵڶ����˵ĵ÷֡�
//�и��߼�Ҫ�������һ������firstPoint���ڶ��������secondPoint�����������ߵ����ֵ������ĵ÷֡� 
int maxPoint(int begin,int len){
	int length=len-begin;
	int firstPoint=0;//��һ��ѡ������ 
	int secondPoint=0;
	//������������������ʾȡһ���ơ������ƺ������Ƶ�������� 
	int onePoint=0;
	int twoPoint=0;
	int threePoint=0; 
	if(length<=3){
		//��ʣ���ȫ��ȡ�ߣ�ʹ��ﵽ���
		for(int i=begin;i<len;i++){
			firstPoint+=arr[i];
			return 0;
		} 
	}
	else if(length==4){
		firstPoint=arr[begin]+arr[begin+1]+arr[begin+2];
		secondPoint=arr[len-1];
		return secondPoint;
	}
	else{//���кܶ�Ԫ��
		onePoint=arr[begin]+maxPoint(begin+1,len);
		twoPoint=arr[begin]+arr[begin+1]+maxPoint(begin+2,len);
		threePoint=arr[begin]+arr[begin+1]+arr[begin+2]+maxPoint(begin+3,len);
		//��onePoint /twoPoint/threePoint ��ȡ���ֵ
		firstPoint=max(onePoint,twoPoint,threePoint); 
		secondPoint=sum(begin,len)-firstPoint;
		return  secondPoint;
	}
	
}
int main(void){
	int k;
	while(scanf("%d",&k)!=EOF&&k>0){
		arr=(int *)malloc(k*sizeof(int));
		if(arr==NULL){
			exit(EXIT_FAILURE);
		}
		for(int i=0;i<k;i++)
			scanf("%d",arr+i);
		int result=sum(0,k)-maxPoint(0,k);//
		printf("%d\n",result);
	}
} 





