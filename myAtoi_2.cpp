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
 

��û�п��ǵĲ�������
1��str="           -012a34";���-12 


��û�п��ǵ��Ĳ�������
1��str="2147483647",�����������ֵ
2��str="- 2147483647",�������

��û�п��ǵ��Ĳ�������
1�� str="9223372036854775809"
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<math.h>

void trimStr(char *str,int *begin,int *end) {
	*begin=0;
	*end=0;
	if(str==NULL||str==""){
		return;
	}
	int index=0;
	
	while(str[index]!='\0'){
		if(str[index]!=' '){
			break;
		}
		index++;
	}
	*begin=index;
	//���жϵ�һ���������ַ��Ƿ�Ϊ  +/-�� 
	if(str[index]=='+'||str[index]=='-'){
		index++;
	} 
	while(str[index]!='\0'){
		if(str[index]==' '){
			break;
		}
		 
		int temp=str[index]-'0';
		if(temp<0||temp>9){
			break;
		} 
		index++;
	}
	*end=index;
}
int myAtoi(char* str) {
	if(str==NULL||str==""){
		return 0;
	} 
	int begin=0;//����ָʾ��һ�����ǿո�������� 
	int end=0;//������ʾ���һ�����ǿո��һλ������ 
	trimStr(str,&begin,&end);
	//���ж���str�ĵ�һ���ַ��Ƿ�Ϊ��+�������ǡ�-����
	int symbol=1;
	int start=begin;
	if(str[begin]=='+'){
		symbol=1;
		start=begin+1;
	} 
	if(str[begin]=='-'){
		symbol=-1;
		start=begin+1; 
	}
	int pow2Val=pow(2,31);
	if(start==end){//ֻ���мӼ��ŵ��ַ����� 
		return 0;
	}
	if(end-start>11){
		if(symbol==1)
			return pow2Val;
		else{
			return (-1)*pow2Val-1;
		}
	}
	long long result=0;//���������� ,ҲҪ�����Ƿ�����������Ϊlong�� 
	for(int i=start;i<end;i++){
		int temp=str[i]-'0';
		if(temp<0||temp>9){//���ÿ���ַ��Ƿ��� '0'��'9'֮�� 
			return 0;
		}
		result=result*10+temp;
	}
	
	
	if(result>=pow2Val&&symbol==1){//����������� ���������������ֵ 
		return pow2Val;
	}
	else if(result>pow2Val&&symbol==-1){//����������� ������С������ֵ
		return  (-1)*pow2Val-1;
	} 
	else{	
		return (int)(symbol*result);
		
	} 
    
}

int main(void){
//	printf("%d",sizeof(long long));
	//char str[1000];
	//while(gets(str)){
	char *    str="9223372036854775809";//2^31-1,��int�������������� 
		int result=myAtoi(str);
		printf("%d\n",result);
//	}
}
