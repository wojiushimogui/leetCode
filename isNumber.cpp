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
思路：检查一个字符串是否是数字
第一步：将字符串前后部分的空格去掉
第二步：检查字符串中是否出现了不是 + - 数字  点  e构成。且+ - 只能出现在字符第一位，点只能出现一次，e不能出现在最后一位？？ 
*/
int dotCount=1;
char* trim(char *s){
	char *result;
	int len=strlen(s);
	int i=0;//寻找第一个不是空格的字符的位置 
	for(;i<len;i++){
		if(s[i]!=' '){
			break;
		}
	}
	int j=len-1;//寻找最后一个不是空格的字符的位置
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
//检查字符是否由数字  e 点 构 成 
bool isVaild(char ch){
	if((ch>='0'&&ch<='9')||ch=='e'){
		return true;
	}
	if(ch=='.'&&dotCount!=0){//控制点'.'只能出现一次 
		dotCount--;
		return true;
	}
	return false; 
}
bool isNumber(char* s) {
	if(s==NULL||strlen(s)<1){
		return false;
	}
    char *s1=trim(s); //去掉字符串前后部分的空格 
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
