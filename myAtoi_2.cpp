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
 

还没有考虑的测试用例
1）str="           -012a34";输出-12 


还没有考虑到的测试用例
1）str="2147483647",正整数中最大值
2）str="- 2147483647",最大负整数

还没有考虑到的测试用例
1） str="9223372036854775809"
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<math.h>

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
	//先判断第一个非数字字符是否为  +/-号 
	if(str[index]=='+'||str[index]=='-'){
		index++;
	} 
	while(str[index]!='\0'){
		if(str[index]==' '){
			break;
		}
		 
		int temp=str[index]-'0';
		if(temp<0||temp>9){
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
	int pow2Val=pow(2,31);
	if(start==end){//只含有加减号的字符串。 
		return 0;
	}
	if(end-start>11){
		if(symbol==1)
			return pow2Val;
		else{
			return (-1)*pow2Val-1;
		}
	}
	long long result=0;//用来保存结果 ,也要考虑是否溢出，因此设为long型 
	for(int i=start;i<end;i++){
		int temp=str[i]-'0';
		if(temp<0||temp>9){//检测每个字符是否在 '0'到'9'之间 
			return 0;
		}
		result=result*10+temp;
	}
	
	
	if(result>=pow2Val&&symbol==1){//正整数溢出了 ，返回最大正整数值 
		return pow2Val;
	}
	else if(result>pow2Val&&symbol==-1){//负整数溢出了 ，返回小负整数值
		return  (-1)*pow2Val-1;
	} 
	else{	
		return (int)(symbol*result);
		
	} 
    
}

int main(void){
//	printf("%d",sizeof(long long));
	//char str[1000];
	//while(gets(str)){
	char *    str="9223372036854775809";//2^31-1,即int类型最大的正整数 
		int result=myAtoi(str);
		printf("%d\n",result);
//	}
}
