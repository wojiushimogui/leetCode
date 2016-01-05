#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
����Ƚϼ򵥣������ַ�����Сд��ĸ���ɣ�ֱ�ӽ���һ������Ϊ26�Ŀռ䣬Ȼ����ַ������б�������
*/
//�ж�indexλ�õ��ظ��ַ��Ƿ���Ⱥ�����ͬ���ַ���Ҫʹ�����ַ���С
char* removeDuplicateLetters(char* s) {
    if(s==NULL){
        return NULL;
    }
    int spaceLen=26;
    int *count=(int *)malloc(spaceLen*sizeof(int));//����ͳ���ַ���s��ÿ���ַ����ֵĴ��� 
    if(count==NULL){
        exit(EXIT_FAILURE);
    }
    memset(count,0,spaceLen*sizeof(int));//��ʼ��Ϊ��
    int len=strlen(s);
    for(int i=0;i<len;i++){
        count[s[i]-'a']++;
    }
    //��flag��Ϊtrue���ַ�����������ؼ���
    //����һ�οռ���������
    char *res=(char *)malloc(spaceLen*sizeof(char));
    if(res==NULL){
        exit(EXIT_FAILURE);
    }
    bool *isExistInRes=(bool *)malloc(spaceLen*sizeof(bool));//������ʶ����Ƿ��Ѿ������˸��ַ� 
	if(isExistInRes==NULL){
		exit(EXIT_FAILURE);
	} 
	memset(isExistInRes,false,spaceLen*sizeof(bool));//��ʼ��Ϊ��
	char ch;
	char sc;
	int end=-1;
	for(int i=0;i<len;i++){
		ch=s[i];
		if(isExistInRes[ch-'a']){
			count[ch-'a']--;
			continue;
		}
		//ͨ���жϸռ�������Ԫ���Ƿ�Ӧ�ü��룬��������Ԫ��С�ڸոռ����Ԫ�ز������Ԫ�ز������һ�γ��֣���Ӧ�ò����� 
		while(end>=0&&(sc=res[end])>=ch&&count[sc-'a']>0){
			end--;
			isExistInRes[sc-'a']=false;
		}
		res[++end]=ch;
		count[ch-'a']--;
		isExistInRes[ch-'a']=true; 
		
	}
    res[++end]='\0';
	return res;    
}

int main(void){
	char s[100];
	while(gets(s)){
		char *res=removeDuplicateLetters(s);
		printf("%s����Ľ��Ϊ��",s);
		puts(res);
	}
	return 0;
}
