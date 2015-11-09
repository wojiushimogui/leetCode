/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/
#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
char* multiply(char* num1, char* num2) {
    if(num1==NULL||num2==NULL){
    	return NULL;
	}
	int len1=strlen(num1);
	int len2=strlen(num2);
	if(len1<1||len1<1){
		return NULL;
	}
	//进行分组来进行计算
	char *result=(char *)malloc((len1+len2+1)*sizeof(char));//最后一个位置用来放字符'\0' 
	if(result==NULL){
		exit(EXIT_FAILURE);
	} 
	memset(result,'0',(len1+len2+1)*sizeof(char));//初始化为'0';注意：是'0',并不是初始化为 0 
	int carry=0;//用来表示进位，初始化为零 
	int carry_result=0;
	for(int i=len1-1;i>=0;i--){
		int tempNum=num1[i]-'0';
		carry=0;
		for(int j=len2-1;j>=0;j--){
			int val=(num2[j]-'0')*tempNum;
			//然后将此值存储在正确的位置;并考虑进位·这样使得进行加法是正确的。
			int temp=(result[i+j+1]-'0')+val+carry;
			carry=temp/10;
			result[i+j+1]=temp%10+'0';
			if(j==0&&carry>0){//在出内层循环之前，要把最高位的进位进行存储起来  
				result[i+j]=carry+'0';
			}
			printf("%c   ",result[i+j+1]);
		}
		
		printf("\n");
	}
//	bool flag=false;
//	if(carry>0){//如果最高位有进位，则result第一个位置有字符在存储,否则没有 
//		flag=true;
//	}
	//如果没有进位，则要将result最前面的一位去掉。 
	result[len1+len2]='\0';
//	puts(result);
	//把前面的零去掉,使得index指向第一个不为零的下标。如果全部为零，则index=len1+len2,输出一个零即可。 
	int index=0;
	for(;index<len1+len2;index++){
		if(result[index]!='0'){
			break;
		}
	}
	
	return index==len1+len2?(result+index-1):result+index;
	
	
}

int main(void){
	char str1[100];
	char str2[100];
	while(gets(str1)){
		gets(str2);
		puts(multiply(str1,str2));
		printf("\n");
	}
	return 0;
}
