

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* getPermutation(int n, int k) {
    if(n<1||k<1){
		return NULL; 
	}
	//����һ�οռ��������� 
	char* result=(char *)malloc((n+1)*sizeof(char));
	if(result==NULL){
		exit(EXIT_FAILURE);
	}
	//����һ�οռ䣬������1~n���ַ� 
	char *s=(char *)malloc((n)*sizeof(char));
	if(s==NULL){
		exit(EXIT_FAILURE);
	} 
	int count=1; //������ʾn�� 
	for(int i=0;i<n;i++){
		s[i]=(char)(i+'1');
		count*=(i+1);
	}
	//������ÿһλ��Ӧ���ַ� 
	k--;//��һ��ԭ�����ڣ��ڣ�n-1��!������Ӧ������1��ͷ�����һ�����У��������һ����������2��ͷ�ĵ�һ�� 
	for(int i=0;i<n;i++){
		count=count/(n-i);
		int index=k/count;
		result[i]=s[index];
		for(int j=index;j<n-i-1;j++){//��s�����Ԫ����ǰ 
			s[j]=s[j+1];
		}
		//����k
		k=k%count; 
		
	} 
	result[n]='\0';
	return result;
}

int main(void){
	
	int n,k;
	while(scanf("%d%d",&n,&k)!=EOF&&n>0&&k>0){
		char *result=getPermutation(n,k);
		
		puts(result);
	}
	return 0;
}
