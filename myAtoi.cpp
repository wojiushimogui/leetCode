/*
���ܵĲ����������£�
1��str="123"
2)str="0123"
3)str="+123"
4)str="-123"
5)str="+0123"
6)str="-0123"
7)�������룺NULL 

û�п��ǵ��Ĳ�������
1��str="    010";��str="010      ";���ո������������������ַ�����ǰ��ո�ȥ���� 
 

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
int myAtoi(char* str) {
	if(str==NULL||str=""||str=" "){
		return 0;
	} 
	int len=strlen(str);
	//���ж���str�ĵ�һ���ַ��Ƿ�Ϊ��+�������ǡ�-����
	int symbol=1;
	int start=0;
	if(str[0]=='+'){
		symbol=1;
		start=1;
	} 
	if(str[0]=='-'){
		symbol=-1;
		start=1; 
	}
	long result=0;//���������� ,ҲҪ�����Ƿ�����������Ϊlong�� 
	for(int i=start;i<len;i++){
		int temp=str[i]-'0';
		if(temp<0||temp>9){//���ÿ���ַ��Ƿ��� '0'��'9'֮�� 
			return 0;
		}
		result=result*10+temp;
	}
	if(result>>31){//����� 
		return 0;
	}
	else{
		return symbol*result;
	} 
    
}

int main(void){
	//char str[1000];
	//while(gets(str)){
	//char *    str="010      ";
	char *    str=" ";
		int result=myAtoi(str);
		printf("%d\n",result);
//	}
}
