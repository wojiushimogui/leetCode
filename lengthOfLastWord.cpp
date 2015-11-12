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
	//先找到最后一个word的终点。 
	for(int i=len-1;i>=0;i--){
		if(s[i]!=32){//32是空格字符的ASCII码 
			pos=i;
			break; 
		}
	}
	if(pos==-1)//没有单词 
		return 0;
	int  count=0;
	for(int i=pos;i>=0;i--){
		if(s[i]==32){//碰到了倒数第一个空格，就退出 
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
