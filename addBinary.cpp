#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char* addBinary(char* a, char* b) {
    int len1=strlen(a);
    int len2=strlen(b);
    
    //����һ�οռ���������
    int len=((len1>=len2)?len1:len2);
    char *result=(char *)malloc((len+2)*sizeof(char));//�࿪�����������һ�������洢'\0',��һ������������ߵĽ�λ
    result[len+1]='\0';
    int i=len1-1;
    int j=len2-1;
    int ci=0;//��ʾ��λ
    int index=len;
    for(;i>=0&&j>=0;i--,j--){
        int temp=(a[i]-'0')+(b[j]-'0')+ci;
        result[index]=temp%2+'0';
        index--;
        ci=temp/2;
        
    }
    char *remainArr;
    int k=0;
    if(i<0){
        remainArr=b;
         k=j;
    }
    else if(j<0){
        remainArr=a;
        k=i;
    }
    //��ʣ��Ľ����������
        for(;k>=0;k--){
            int temp=(remainArr[k]-'0')+ci;
            result[index]=temp%2+'0';
            index--;
            ci=temp/2;
        }
        if(ci>0){//���λ�н�λ
            result[index]=ci+'0';
            return result;
        }
        else{
            return result+1;
        }
 
}
int main(void){
		char *s1="11";
		char *s2="1";
		char *res=addBinary(s1,s2);
		puts(res);  
	return 0;
} 
