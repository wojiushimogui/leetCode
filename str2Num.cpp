#include<stdio.h>
#include<stdlib.h> 
#include<string.h> 
/*
将字符串转化为整数 ,如果字符串中包括小数点、字符e，就更加复杂了。 
*/
enum Staus{
	kValid=0,
	kInvalid,
};
int g_staus=kValid;
int str2Num(char *str){
	g_staus=kInvalid;
	int len=strlen(str);
	if(str==NULL||len<1){
		return 0;
	}
	int minus=0;
	//先判断这个字符的第一个字符是不是 +  - 号 
	char *digits=str;
	if(*digits=='-'){
		minus=1;
		digits++;
	} 
	else if(*digits=='+'){
		digits++;
	}
	//接着开始转换
	int num=0;
	while(*digits!='\0'){
		char temp=*digits;
		if('0'<=temp&&temp<='9'){
			num*=10+temp;
			//注意：最好判断下num是否已经溢出
			if(num>INT_MAX){
				num=0;
				break;
			} 
			digits++;
		}
		else{//如果不是数字字符，则直接退出，即可 
			num=0;
			break;
		}
	}
	if(*digits=='\0'){
		g_staus=kValid;
		if(minus==1){
			num=0-num;
		}
	} 
	return num;
}
