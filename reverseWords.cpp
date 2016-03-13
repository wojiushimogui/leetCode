#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
���η�ת���ɽ�� 
*/
void swap(char *a,char *b){
	char temp=*a;
	*a=*b;
	*b=temp;
}
void reverse(char *s,int begin,int end){
	if(s==NULL||end<=begin){
		return;
	}	
	while(begin<end){
		swap(&s[begin],&s[end]);
		begin++;
		end--;
	}
} 
char *trim(char *s){
	if(s==NULL){
		return NULL;
	}
	int begin=0;
	int len=strlen(s); 
	int end=len-1;
	while(s[begin]==' '&&begin<len){
		begin++;
	}
	while(s[end]==' '&&end>=0){
		end--;
	}
	if(end<begin){//�������˵�����ַ���ȫ��Ϊ�ո񹹳�  
		return "";
	}
	//�ѵ���֮��Ķ��������ո��ɾ����
	int blankCount=0;
	int index=begin;//ע�⣺������begin 
	for(int i=begin;i<=end;i++){
		if(s[i]==' '){
			blankCount++;
		}
		else{
			if(blankCount>1){//�һ���ո�				
				s[index]=' ';
				index++;
				blankCount=0;//ע������ 
			}			
			s[index]=s[i];
			index++;						
		}
	} 
	s[index]='\0';//��һ���ַ��������� 
	return &s[begin];
}

void reverseWords(char *s) {
    if(s==NULL){
    	return ;
	}
	s=trim(s);
	//puts(s);
//	printf("����Ϊ��",strlen(s));
	if(s==""){
		return;
	}	
	//puts(s); 
	int len=strlen(s);	
	//��ÿ�����ʽ��з�ת
	for(int start=0;start<len;start++){
		if(s[start]!=' '){
			int end=start;
			while(s[end]!=' '&&end<len){
				end++;
			}
			//������start ~end-1����һ������
			reverse(s,start,end-1); 
			start=end;//����start ��������start=end+1����Ϊforѭ������Ϊ���1
		}
	}
	//puts(s);
	reverse(s,0,len-1); 	
}
int main(void){
	char s[100];
	gets(s);
	reverseWords(s)	;
	puts(s);
} 
