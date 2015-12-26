/*
思路2，为了简化时间复杂度，我们采用动态规划的方法。
例如，当我们知道了n-2长度的字符串能够解释的数目以及n-1长度的字符串能够解释的数目时，我们可以判读如下两个条件：
1）若第n个字符在1到9之间，则n长度的字符串能够解释的数目包含n-1长度字符串能够解释的数目。
2）若第n-1个字符与第n个字符可以解释为一个字母时，则n长度的字符串能够解释的数目包含n-2长度字符串能够解释的数目。
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int char2num(char ch){
	return ch-'0';
}
int numDecodings(char* s) {
    if(s==NULL||strlen(s)<=0){
    	return 0;
	}
	int len=strlen(s);
	if(len==1){
		return (s[0]!='0')?1:0;
	}
	else if(len==2){//求出字符长度为2的译码方法。 
		return ((s[0]!='0'&&s[1]!='0')?1:0)+((s[0]!='0'&&(char2num(s[0])*10+char2num(s[1])<=26))?1:0);
	}
	//用来保存结果 
	int *res=(int *)malloc(len*sizeof(int));
	if(res==NULL){
		exit(EXIT_FAILURE);
	} 
	memset(res,0,len*sizeof(int));
	res[0]= (s[0]!='0')?1:0;
	res[1]=((s[0]!='0'&&s[1]!='0')?1:0)+((s[0]!='0'&&(char2num(s[0])*10+char2num(s[1])<=26))?1:0);
	for(int i=2;i<len;i++){
		if(s[i]!='0'){//1）若第n个字符在1到9之间，则n长度的字符串能够解释的数目包含n-1长度字符串能够解释的数目。
			res[i]+=res[i-1];
		}
		//2）若第n-1个字符与第n个字符可以解释为一个字母时，则n长度的字符串能够解释的数目包含n-2长度字符串能够解释的数目。
		if(s[i-1]!='0'&&char2num(s[i-1])*10+char2num(s[i])<=26){//
			res[i]+=res[i-2];
		}
	}
	return res[len-1];
	
}
int main(void){
	
}
