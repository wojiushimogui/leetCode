/*
可能的测试用例如下：
1）str="123"
2)str="0123"
3)str="+123"
4)str="-123"
5)str="+0123"
6)str="-0123"
7)特殊输入：NULL 

没有考虑到的测试用例
1）str="    010";或str="010      ";含空格的情况。处理方法：将字符串的前后空格去除了 
 

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
int myAtoi(char* str) {
	if(str==NULL||str=""||str=" "){
		return 0;
	} 
	int len=strlen(str);
	//先判断下str的第一个字符是否为“+”或者是“-”号
	int symbol=1;
	int start=0;
	if(str[0]=='+'){
		symbol=1;
		start=1;
	} 
	if(str[0]=='-'){
		symbol=-1;
		start=1; 
	}
	long result=0;//用来保存结果 ,也要考虑是否溢出，因此设为long型 
	for(int i=start;i<len;i++){
		int temp=str[i]-'0';
		if(temp<0||temp>9){//检测每个字符是否在 '0'到'9'之间 
			return 0;
		}
		result=result*10+temp;
	}
	if(result>>31){//溢出了 
		return 0;
	}
	else{
		return symbol*result;
	} 
    
}

int main(void){
	//char str[1000];
	//while(gets(str)){
	//char *    str="010      ";
	char *    str=" ";
		int result=myAtoi(str);
		printf("%d\n",result);
//	}
}
