/*
1����i�Ŵ�i��ʼ
2�� ��numRows��ÿ������֮���Ԫ�صļ��Ϊstep=2*(numRows-1) 
3��б�������Ԫ�ؼ��Ϊ��step=j+step-2*i;����jΪs�е��±꣬iΪ���±꣨���㿪ʼ�� 
*/ 

#include<stdio.h>
#include<stdlib.h>
#include<string.h> 

char* convert(char* s, int numRows) {
    if(s==NULL||numRows<1){
    	return NULL;
	}
	
	int len=strlen(s);
	if(numRows==1||numRows>=len){//������Ϊ1��numRows>=lenʱ��ֱ��������� 
		return s;
	} 
	char *str=(char *)malloc((len+1)*sizeof(char));//������������ 
	if(str==NULL){
		exit(EXIT_FAILURE);
	} 
	//
	int index=0;
	for(int i=0;i<numRows;i++){//����
		int step=2*(numRows-1);
		for(int j=i;j<len;j+=step){
			str[index]=s[j];
			index++;
			if(i==0||i==numRows-1){ 
				continue;
			}
			//����һ�к����һ��֮�⣬��Ҫ������Ԫ��֮����� ��б���ϡ�Ԫ��
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
