#include<stdio.h>
#include<stdlib.h> 
#include<string.h> 
/*
���ַ���ת��Ϊ���� ,����ַ����а���С���㡢�ַ�e���͸��Ӹ����ˡ� 
*/
enum Staus{
	kValid=0,
	kInvalid,
};
int g_staus=kValid;
int str2Num(char *str){
	g_staus=kInvalid;
	int len=strlen(str);
	if(str==NULL||len<1){
		return 0;
	}
	int minus=0;
	//���ж�����ַ��ĵ�һ���ַ��ǲ��� +  - �� 
	char *digits=str;
	if(*digits=='-'){
		minus=1;
		digits++;
	} 
	else if(*digits=='+'){
		digits++;
	}
	//���ſ�ʼת��
	int num=0;
	while(*digits!='\0'){
		char temp=*digits;
		if('0'<=temp&&temp<='9'){
			num*=10+temp;
			//ע�⣺����ж���num�Ƿ��Ѿ����
			if(num>INT_MAX){
				num=0;
				break;
			} 
			digits++;
		}
		else{//������������ַ�����ֱ���˳������� 
			num=0;
			break;
		}
	}
	if(*digits=='\0'){
		g_staus=kValid;
		if(minus==1){
			num=0-num;
		}
	} 
	return num;
}
