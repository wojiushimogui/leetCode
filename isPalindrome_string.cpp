#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.
*/
/*
˼·�������е��ַ�ת��ΪСд��ĸ�洢��һ�������У�Ȼ��������ǰ��ָ������ƶ��Ƚϼ��� 
ע�⣺Ҫ����ȫ���ǿո���ַ��� 
*/
bool isValid(char ch){
	if(('a'<=ch&&ch<='z')||('A'<=ch&&ch<='Z')||('0'<=ch&&ch<='9')){
		return true;
	}
	else{
		return false;
	}
}
char capitalTolowercase(char ch){
	if('A'<=ch&&ch<='Z'){
		return ch+32;
	}
	else {
		return ch;
	}
}
bool isPalindrome(char* s) {
    if(s==NULL){
    	return true;
	} 
	int len=strlen(s);
	int begin=0;
	int end=len-1;
	while(begin<end){
		if(isValid(s[begin])&&isValid(s[end])){
			if(capitalTolowercase(s[begin])==capitalTolowercase(s[end])){
				begin++;
				end--;
			}
			else{
				return false;
			}
		}
		else if(!isValid(s[begin])&&isValid(s[end])){
			begin++;
		}
		else if(isValid(s[begin])&&!isValid(s[end])){
			end--;
		}
		else if(!isValid(s[begin])&&!isValid(s[end])){
			begin++;
			end--;
		}
	}
	return true;	
}
