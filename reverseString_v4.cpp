#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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

void reverseWords(char *s) {
    if(s==NULL){
    	return ;
	}
	int len=strlen(s);	
	//对每个单词进行翻转
	for(int start=0;start<len;start++){
		if(s[start]!=' '){
		    int begin=start;
			while(start+1<len&&s[start+1]!=' '){
				start++;
			}
			reverse(s,begin,start); 
		}
		//经过上面的处理之后，start+1指向的就是空格
		while(start+1<len&&s[start+1]==' '){
		    start++;
		}
	}
	reverse(s,0,len-1); 	
}
