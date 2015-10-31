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
void trimStr(char *str,int *begin,int *end) {
	*begin=0;
	*end=0;
	if(str==NULL||str==""){
		return;
	}
	int index=0;
	
	while(str[index]!='\0'){
		if(str[index]!=' '){
			break;
		}
		index++;
	}
	*begin=index;
	while(str[index]!='\0'){
		if(str[index]==' '){
			break;
		}
		index++;
	}
	*end=index;
}
int myAtoi(char* str) {
	if(str==NULL||str==""){
		return 0;
	} 
	int begin=0;//用来指示第一个不是空格的索引； 
	int end=0;//用来表示最后一个不是空格后一位的索引 
	trimStr(str,&begin,&end);
	//先判断下str的第一个字符是否为“+”或者是“-”号
	int symbol=1;
	int start=begin;
	if(str[begin]=='+'){
		symbol=1;
		start=begin+1;
	} 
	if(str[begin]=='-'){
		symbol=-1;
		start=begin+1; 
	}
	if(start==end){//只含有加减号的字符串。 
		return 0;
	}
	long result=0;//用来保存结果 ,也要考虑是否溢出，因此设为long型 
	for(int i=start;i<end;i++){
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
	char *    str=" ";
		int result=myAtoi(str);
		printf("%d\n",result);
//	}
}
