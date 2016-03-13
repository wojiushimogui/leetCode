#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
两次翻转即可解决 
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
	if(end<begin){//此种情况说明此字符串全部为空格构成  
		return "";
	}
	//把单词之间的多余两个空格的删除掉
	int blankCount=0;
	int index=begin;//注意：这里是begin 
	for(int i=begin;i<=end;i++){
		if(s[i]==' '){
			blankCount++;
		}
		else{
			if(blankCount>1){//填补一个空格				
				s[index]=' ';
				index++;
				blankCount=0;//注意清零 
			}			
			s[index]=s[i];
			index++;						
		}
	} 
	s[index]='\0';//补一个字符串结束符 
	return &s[begin];
}

void reverseWords(char *s) {
    if(s==NULL){
    	return ;
	}
	s=trim(s);
	//puts(s);
//	printf("长度为：",strlen(s));
	if(s==""){
		return;
	}	
	//puts(s); 
	int len=strlen(s);	
	//对每个单词进行翻转
	for(int start=0;start<len;start++){
		if(s[start]!=' '){
			int end=start;
			while(s[end]!=' '&&end<len){
				end++;
			}
			//这样，start ~end-1就是一个单词
			reverse(s,start,end-1); 
			start=end;//更新start ，但不是start=end+1，因为for循环还会为其加1
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
