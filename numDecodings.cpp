#include<stdio.h>
#include<string.h>
//思路：利用递归来进行求解
bool flag=false;
int numDecodings(char* s) {
    if(s==NULL) return 0;
    int len=strlen(s);
    if(len==0) return 0;
    for(int i=0;i<len;i++){//先检查是否有非法字符
        if(!(s[i]>='0'&&s[i]<='9')){
            return 0;
        }
    }
    if(len==1){
        if(s[0]=='0') return 0;
        else  return 1;
        
    }
    int result=0;
    //下面为大于等于2的情况。
    if(s[0]=='1'||(s[0]=='2'&&s[1]<='6')){
        result= numDecodings(s+1)+numDecodings(s+2);
    }
    else{
        result= numDecodings(s+1);
    }
    return result+1;
}

int main(void){
	char s[20];
	while(gets(s)){
		int result=numDecodings(s);
		printf("%d\n",result);
	}
	
}
