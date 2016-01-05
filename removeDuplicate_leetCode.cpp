#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
此题比较简单，由于字符串由小写字母构成，直接借助一个长度为26的空间，然后对字符串进行遍历即可
*/
//判断index位置的重复字符是否相比后面相同的字符的要使整个字符最小
char* removeDuplicateLetters(char* s) {
    if(s==NULL){
        return NULL;
    }
    int spaceLen=26;
    int *count=(int *)malloc(spaceLen*sizeof(int));//用来统计字符串s中每个字符出现的次数 
    if(count==NULL){
        exit(EXIT_FAILURE);
    }
    memset(count,0,spaceLen*sizeof(int));//初始化为零
    int len=strlen(s);
    for(int i=0;i<len;i++){
        count[s[i]-'a']++;
    }
    //将flag中为true的字符组合起来返回即可
    //开辟一段空间来保存结果
    char *res=(char *)malloc(spaceLen*sizeof(char));
    if(res==NULL){
        exit(EXIT_FAILURE);
    }
    bool *isExistInRes=(bool *)malloc(spaceLen*sizeof(bool));//用来标识结果是否已经存在了该字符 
	if(isExistInRes==NULL){
		exit(EXIT_FAILURE);
	} 
	memset(isExistInRes,false,spaceLen*sizeof(bool));//初始化为零
	char ch;
	char sc;
	int end=-1;
	for(int i=0;i<len;i++){
		ch=s[i];
		if(isExistInRes[ch-'a']){
			count[ch-'a']--;
			continue;
		}
		//通过判断刚加入的这个元素是否应该加入，如果后面的元素小于刚刚加入的元素并且这个元素不是最后一次出现，则应该不加入 
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
		printf("%s输出的结果为：",s);
		puts(res);
	}
	return 0;
}
