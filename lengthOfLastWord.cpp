#include<stdio.h>
#include<stdlib.h> 
#include<string.h>

int lengthOfLastWord(char* s) {
    if(s==NULL){
    	return 0;
	}
	puts(s);
	int len=strlen(s);
	if(len<1){
		return 0;
	}
	int pos=-1;
	//���ҵ����һ��word���յ㡣 
	for(int i=len-1;i>=0;i--){
		if(s[i]!=32){//32�ǿո��ַ���ASCII�� 
			pos=i;
			break; 
		}
	}
	if(pos==-1)//û�е��� 
		return 0;
	int  count=0;
	for(int i=pos;i>=0;i--){
		if(s[i]==32){//�����˵�����һ���ո񣬾��˳� 
			break;
		}
		count++;
	} 
	return count; 
	
}

int main(void){
	char str[100];
	while(gets(str)){
		printf("%d \n",lengthOfLastWord(str));
	}
}
