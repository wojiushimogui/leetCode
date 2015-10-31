/*
1、第i排从i开始
2、 含numRows的每列相邻之间的元素的间隔为step=2*(numRows-1) 
3、斜线上面的元素间隔为：step=j+step-2*i;其中j为s中的下标，i为行下标（从零开始） 
*/ 

#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

char* convert(char* s, int numRows) {
    if(s==NULL||numRows<1){
    	return NULL;
	}
	
	int len=strlen(s);
	if(numRows==1||numRows>=len){//当行数为1且numRows>=len时，直接输出即可 
		return s;
	} 
	char *str=(char *)malloc((len+1)*sizeof(char));//用来保存结果。 
	if(str==NULL){
		exit(EXIT_FAILURE);
	} 
	//
	int index=0;
	for(int i=0;i<numRows;i++){//行数
		int step=2*(numRows-1);
		for(int j=i;j<len;j+=step){
			str[index]=s[j];
			index++;
			if(i==0||i==numRows-1){ 
				continue;
			}
			//除第一行和最后一行之外，需要在两个元素之间加上 “斜线上”元素
			int slashIndex=j+step-2*i;
			if(slashIndex<len){
				str[index]=s[slashIndex]; 
				index++;
			}
			
		} 
		
	} 
	str[len]='\0';
	return str; 
	
}

int main(void){
	char s[1000];
	int k;
	while(gets(s)){
		puts(s);
			scanf("%d",&k);
			char *result=convert(s,k);
			puts(result);
		
	}
}
