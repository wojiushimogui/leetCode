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
第二步：站在字符e的角度开始检查， e只能出现一次，e不能出现在第一位和最后一位 ，e的前面可以是数字和点，
e的后面可以是数字和加减号，但是加减号不能是最后一位 ；记录字符e和e后面加减号的位置 
第三步：检查整个字符串中是否出现了不是 + - 数字  。且+ - 只能出现在字符第一位（除e后面的加减号之外），点只能出现一次，， 
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
	for(;j>=0;j--){
		if(s[j]!=' '){
			break;
		}
	}
	result=(char *)malloc((j-i+2)*sizeof(char));
	for(int k=i;k<=j;k++){
		result[k-i]=s[k];
	} 
	result[j-i+1]='\0';
	//puts(result);
	return result;
}
//检查字符是否由数字  e 点 构 成 
bool isVaild(char ch){
	if((ch>='0'&&ch<='9')){
		return true;
	}
	if(ch=='.'&&dotCount!=0){//控制点'.'只能出现一次 
		dotCount--;
		return true;
	}
	return false; 
}
bool isdot(char *s,int begin,int end) {
	if(s==NULL||end<begin){
		return false;
	}
	for(int i=begin;i<end;i++){
		if(s[i]=='.'){
			return false;
		}
	}
	return true;
}
bool isNumber(char* s) {
	if(s==NULL||strlen(s)<1){//有效性检查 
		return false;
	}
    dotCount=1;
	int eCount=1;
    char *s1=trim(s); //去掉字符串前后部分的空格 
    int len=strlen(s1);
    if(len<1){//检查下去掉空格后的字符串长度是否大于1 
        return false;
    }
    int eIndex=-1;//保存e出现的位置  
    int markIndex=-1;//保存e后面加号的位置 
    for(int i=0;i<len;i++){//检查下e前面和后面是否是一个数字
    	
		if(s1[i]=='e'){
			if(eCount==0){//e只允许出现一次 
				return false;
			}
			eCount--;
			eIndex=i;//记录e出现的位置 
			if(i==0||i==len-1){//e不允许出现在第一位和最后一位的位置 
				return false;
			}
			else{
				//e的前面一定要是数字或者是. 
				if(!(s1[i-1]>='0'&&s1[i-1]<='9'||(dotCount==1&&s1[i-1]=='.'))){
					return false;
				}
				//e的后面不可以有点，例如：3e. ，3e3.8 
				if(!isdot(s1,i+1,len)){//e的后面不允许出现点
					return false;
				}
				//加e的后面 可以出现加减号 ,记录其出现的位置 ,如果出现加减号，则加减号必须不是最后一位 
				if(s1[i+1]=='+'||s1[i+1]=='-'){
					markIndex=i+1;
					if(markIndex==len-1){//如果出现加减号，则加减号必须不是最后一位
						return false;
					} 
					continue;
				}
				if(!(s1[i+1]>='0'&&s1[i+1]<='9')){ 
					return  false; 
				}
			}
		} 
    	
	}
	
    for(int i=0;i<len;i++){
    	if(i==markIndex||i==eIndex){
    		continue;
		} 
    	if(i==0){
    		//第0号位置可以出现加减号和符号点 
    		if(s1[0]=='+'||s1[0]=='-'||s1[0]=='.'){
    			if(s1[0]=='.'){
    		        dotCount--;//控制点的数量为1 
    		    }
    		    if(len==1){//不允许出现只有一个 + - .
    		        return false;
    		    }
    		    else  {//如果长度大于1，则加号、减号、和点后面一定要是一个数字,加号和减号后面可以是一个点 
    		    	if((dotCount==1&&s1[1]=='.'&&len==2)){//不允许出现像这样的“-."数字 
    		    		return false;
					}
					else if(!(s1[1]>='0'&&s1[1]<='9'||dotCount==1&&s1[1]=='.')){
						return false;
					}
    		    	
				}
    		    
    			continue;
			}
		}
    	if(!isVaild(s1[i])){
    		return false;
		}
	}
	return true;
}


int main(void){
	char str[50];
	while(gets(str)){
		
		bool result=isNumber(str);
		if(result){
			printf("true\n");
		}
		else{
			printf("false\n");
		}
	}
	return 0;
}
