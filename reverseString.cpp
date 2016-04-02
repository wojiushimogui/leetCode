#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void swap(char *a,char *b){
	char temp=*a;
	*a=*b;
	*b=temp;
}
void reverseWord(char *str,int start,int end){
	if(str==NULL||start>=end){
		return;
	}
	while(start<end){
		swap(&str[start],&str[end]);
		start++;
		end--;
	}
}

void reverseString(char *str){
	if(str==NULL){
		return;
	} 
	int len=strlen(str); 
	//��һ������תÿ�����ʡ�
	int i=0;
	int start=0;
	int end=0;
	for(;i<len;i++){
		if(str[i]!=' '){
			start=i;
			while(i<len&&str[i]!=' '){
				i++;
			}
			end=i-1;
			reverseWord(str,start,end);			
		}
	}
	//puts(str);
	//�ڶ�������ת�����ַ���
	reverseWord(str,0,len-1); 
}

int main(void){
	char s[100];
	gets(s);
	reverseString(s)	;
	puts(s);
}
