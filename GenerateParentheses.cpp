/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
/*
˼·������ֻ��һ�����ţ��Ϸ��Ծ������κ�λ����������ߵ�'('һ����С��')�ĸ���

����һ��'('֮�������λ�þ�����������һ��λ�õ�')'���н���

*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void swap(char *a,char *b){
    char temp=*a;
    *a=*b;
    *b=temp;
}
char** generateParenthesis(int n, int* returnSize) {
    if(n<1){
        *returnSize=0;
        return NULL;
    }
    //�Ƚ�����������������������ʽ��������
    char *temp=(char *)malloc((2*n+1)*sizeof(char));
    if(temp==NULL)
        exit(EXIT_FAILURE);
    
    for(int i=0;i<2*n;i++){
        if(i<n){
            temp[i]='(';
        }
        else{
            temp[i]=')';
        }
    }
    temp[2*n]='\0';
    //�Ƚ�temp����Ҫresult�ĵ�һ��λ��
    int total=(n-1)*(n-1)+1;//�����Ź��ɵĺϷ�������
    char **result=(char **)malloc(total*sizeof(char *));
    int index=0;
    result[index]=(char *)malloc((2*n+1)*sizeof(char));
    if(result[index]==NULL)
        exit(EXIT_FAILURE);
    strcpy(result[index],temp);
    index++;
    // char* copyTemp=(char *)malloc((2n+1)*sizeof(char));
    // if(copyTemp==NULL)
    //     exit(EIXT_FAILURE);
    for(int i=1;i<n;i++){
        // //��һ������temp����Ҫ�µ�һ����ʱ�����У�ʹcopyTempʼ�ձ���Ϊtemp��һ������
        // strcpy(copyTemp,temp);
        //�ڶ�������copyTemp�г���һ��'('֮�������λ�þ�����������һ��λ�õ�')'���н���
        for(int j=n;j<2*n-1;j++){
            swap(&temp[i],&temp[j]);
            result[index]=(char *)malloc((2*n+1)*sizeof(char));
            if(result[index]==NULL)
                exit(EXIT_FAILURE);
            strcpy(result[index],temp);
            index++;
            swap(&temp[j],&temp[i]);//�ٽ�temp��ԭ
            
            
        }
    }
    *returnSize=index;
    return result;
    
}

int main(void){
	int k;
	while(scanf("%d",&k)!=EOF&&k>0){
		int returnSize=0;
		char **result=generateParenthesis(k, &returnSize);
		for(int i=0;i<returnSize;i++){
			puts(result[i]);
		}
	}
}
