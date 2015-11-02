
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int findMinStrLen(char **strs,int strsSize){
    if(strs==NULL||strsSize<1){
        return NULL;
    }
    int minLen=strlen(strs[0]);
    for(int i=1;i<strsSize;i++){
        int len=strlen(strs[i]);
        if(minLen>len){
            minLen=len;
        }
    }
    return minLen;
}
//��鳤��ΪstrsSize���ַ�������strs����index�±��Ƿ�ȫ����ͬ
bool sameAllStrs(char **strs,int strsSize,int index){
    if(strs==NULL||strsSize<1||index<0){
        return false;
    }
    char ch=strs[0][index];
    for(int i=1;i<strsSize;i++){
        char temp=strs[i][index];
        if(ch!=temp){
            return false;
        }
    }
    return true;
    
}
char* longestCommonPrefix(char** strs, int strsSize) {
    if(strs==NULL||strsSize<1){
        return NULL;
    }
    //Ѱ����Ĺ����ַ�ǰ׺��ͨ����������
    //��ȷ����̵��ַ����ĳ��ȡ�
    int minLen=findMinStrLen(strs,strsSize);
    int index=0;
    while(index<minLen){
        if(sameAllStrs(strs,strsSize,index)){
            index++;
        }
        else{
            break;
        }
    }
    char *str=(char *)malloc((index+2)*sizeof(char));
    for(int i=0;i<index+1;i++){
    	str[i]=strs[0][i];
	}
	str[index+1]='\0';
    return str;
}

int main(void){
	char strs[3][10]={"wug","wurag","wuhang"};;
	puts(longestCommonPrefix((char **)strs,3));
}
