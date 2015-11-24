#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous.
 You should gather all requirements up front before implementing one.
*/
/*
˼·�����һ���ַ����Ƿ�������
��һ�������ַ���ǰ�󲿷ֵĿո�ȥ��
�ڶ���������ַ������Ƿ�����˲��� + - ����  ��  e���ɡ���+ - ֻ�ܳ������ַ���һλ����ֻ�ܳ���һ�Σ�e���ܳ��������һλ���� 
*/
int dotCount=1;
char* trim(char *s){
	char *result;
	int len=strlen(s);
	int i=0;//Ѱ�ҵ�һ�����ǿո���ַ���λ�� 
	for(;i<len;i++){
		if(s[i]!=' '){
			break;
		}
	}
	int j=len-1;//Ѱ�����һ�����ǿո���ַ���λ��
	for(;j>=0;j++){
		if(s[j]!=' '){
			break;
		}
	}
	result=(char *)malloc((j-i+2)*sizeof(char));
	for(int k=i;k<=j;k++){
		result[k-i]=s[k];
	} 
	result[j-i+1]='\0';
	return result;
}
//����ַ��Ƿ�������  e �� �� �� 
bool isVaild(char ch){
	if((ch>='0'&&ch<='9')||ch=='e'){
		return true;
	}
	if(ch=='.'&&dotCount!=0){//���Ƶ�'.'ֻ�ܳ���һ�� 
		dotCount--;
		return true;
	}
	return false; 
}
bool isNumber(char* s) {
	if(s==NULL||strlen(s)<1){
		return false;
	}
    char *s1=trim(s); //ȥ���ַ���ǰ�󲿷ֵĿո� 
    int len=strlen(s1);
    for(int i=0;i<len;i++){
    	if(i==0){
    		if(s1[0]=='+'||s1[0]=='-'){
    			continue;
			}
		}
    	if(!isVaild(s1[i])){
    		return false;
		}
	}
	return true;
}
