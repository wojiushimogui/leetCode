/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/
#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
char* multiply(char* num1, char* num2) {
    if(num1==NULL||num2==NULL){
    	return NULL;
	}
	int len1=strlen(num1);
	int len2=strlen(num2);
	if(len1<1||len1<1){
		return NULL;
	}
	//���з��������м���
	char *result=(char *)malloc((len1+len2+1)*sizeof(char));//���һ��λ���������ַ�'\0' 
	if(result==NULL){
		exit(EXIT_FAILURE);
	} 
	memset(result,'0',(len1+len2+1)*sizeof(char));//��ʼ��Ϊ'0';ע�⣺��'0',�����ǳ�ʼ��Ϊ 0 
	int carry=0;//������ʾ��λ����ʼ��Ϊ�� 
	int carry_result=0;
	for(int i=len1-1;i>=0;i--){
		int tempNum=num1[i]-'0';
		carry=0;
		for(int j=len2-1;j>=0;j--){
			int val=(num2[j]-'0')*tempNum;
			//Ȼ�󽫴�ֵ�洢����ȷ��λ��;�����ǽ�λ������ʹ�ý��мӷ�����ȷ�ġ�
			int temp=(result[i+j+1]-'0')+val+carry;
			carry=temp/10;
			result[i+j+1]=temp%10+'0';
			if(j==0&&carry>0){//�ڳ��ڲ�ѭ��֮ǰ��Ҫ�����λ�Ľ�λ���д洢����  
				result[i+j]=carry+'0';
			}
			printf("%c   ",result[i+j+1]);
		}
		
		printf("\n");
	}
//	bool flag=false;
//	if(carry>0){//������λ�н�λ����result��һ��λ�����ַ��ڴ洢,����û�� 
//		flag=true;
//	}
	//���û�н�λ����Ҫ��result��ǰ���һλȥ���� 
	result[len1+len2]='\0';
//	puts(result);
	//��ǰ�����ȥ��,ʹ��indexָ���һ����Ϊ����±ꡣ���ȫ��Ϊ�㣬��index=len1+len2,���һ���㼴�ɡ� 
	int index=0;
	for(;index<len1+len2;index++){
		if(result[index]!='0'){
			break;
		}
	}
	
	return index==len1+len2?(result+index-1):result+index;
	
	
}

int main(void){
	char str1[100];
	char str2[100];
	while(gets(str1)){
		gets(str2);
		puts(multiply(str1,str2));
		printf("\n");
	}
	return 0;
}
