/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
/*
思路：由于只有一种括号，合法性就是在任何位置来看，左边的'('一定不小于')的个数

除第一个'('之外的所有位置均可以与除最后一个位置的')'进行交换

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
    //先将（（（）））这个最初的形式保存起来
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
    //先将temp拷贝要result的第一个位置
    int total=(n-1)*(n-1)+1;//由括号构成的合法的总数
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
        // //第一步：将temp拷贝要新的一个临时数组中，使copyTemp始终保持为temp的一个拷贝
        // strcpy(copyTemp,temp);
        //第二步：将copyTemp中除第一个'('之外的所有位置均可以与除最后一个位置的')'进行交换
        for(int j=n;j<2*n-1;j++){
            swap(&temp[i],&temp[j]);
            result[index]=(char *)malloc((2*n+1)*sizeof(char));
            if(result[index]==NULL)
                exit(EXIT_FAILURE);
            strcpy(result[index],temp);
            index++;
            swap(&temp[j],&temp[i]);//再将temp还原
            
            
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
