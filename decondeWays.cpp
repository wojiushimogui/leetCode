/*
˼·2��Ϊ�˼�ʱ�临�Ӷȣ����ǲ��ö�̬�滮�ķ�����
���磬������֪����n-2���ȵ��ַ����ܹ����͵���Ŀ�Լ�n-1���ȵ��ַ����ܹ����͵���Ŀʱ�����ǿ����ж���������������
1������n���ַ���1��9֮�䣬��n���ȵ��ַ����ܹ����͵���Ŀ����n-1�����ַ����ܹ����͵���Ŀ��
2������n-1���ַ����n���ַ����Խ���Ϊһ����ĸʱ����n���ȵ��ַ����ܹ����͵���Ŀ����n-2�����ַ����ܹ����͵���Ŀ��
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int char2num(char ch){
	return ch-'0';
}
int numDecodings(char* s) {
    if(s==NULL||strlen(s)<=0){
    	return 0;
	}
	int len=strlen(s);
	if(len==1){
		return (s[0]!='0')?1:0;
	}
	else if(len==2){//����ַ�����Ϊ2�����뷽���� 
		return ((s[0]!='0'&&s[1]!='0')?1:0)+((s[0]!='0'&&(char2num(s[0])*10+char2num(s[1])<=26))?1:0);
	}
	//���������� 
	int *res=(int *)malloc(len*sizeof(int));
	if(res==NULL){
		exit(EXIT_FAILURE);
	} 
	memset(res,0,len*sizeof(int));
	res[0]= (s[0]!='0')?1:0;
	res[1]=((s[0]!='0'&&s[1]!='0')?1:0)+((s[0]!='0'&&(char2num(s[0])*10+char2num(s[1])<=26))?1:0);
	for(int i=2;i<len;i++){
		if(s[i]!='0'){//1������n���ַ���1��9֮�䣬��n���ȵ��ַ����ܹ����͵���Ŀ����n-1�����ַ����ܹ����͵���Ŀ��
			res[i]+=res[i-1];
		}
		//2������n-1���ַ����n���ַ����Խ���Ϊһ����ĸʱ����n���ȵ��ַ����ܹ����͵���Ŀ����n-2�����ַ����ܹ����͵���Ŀ��
		if(s[i-1]!='0'&&char2num(s[i-1])*10+char2num(s[i])<=26){//
			res[i]+=res[i-2];
		}
	}
	return res[len-1];
	
}
int main(void){
	
}