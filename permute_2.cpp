#include<stdio.h>
#include<stdlib.h>

int **result;
int **index_my=0;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void permute(int *nums,int k,int length){
    if(nums==NULL||length<1){
        return ;
    }
    if(k==length){//当k=length时，说明找到一种情况，将其保存即可
        //先分配内存
        result[index_my]=(int *)malloc(length*sizeof(int));
        if(result[index_my]==NULL){
            exit(EXIT_FAILURE);
        }
        for(int i=0;i<length;i++){
            result[index_my][i]=nums[i];
        }
        index_my++;
        
        
    }
    else{//当k不等于length时，要继续与后面的进行交换后递归
        for(int i=k;i<length;i++){
            if(i!=k&&nums[i]==nums[k])//相同则就不交换
                continue;
            //否则，先交换，再递归
            swap(&nums[k],&nums[i]);
            permute(nums,k+1,length);
            swap(&nums[k],&nums[i]);
            
        }
        
    }
}
int** permuteUnique(int* nums, int numsSize, int* returnSize) {
    if(nums==NULL||numsSize<1){
        return NULL;
    }
    int num=1;
    for(int i=1;i<=numsSize;i++){
        num*=i;
    }
    result=(int **)malloc(num*sizeof(int *));
    if(result==NULL){
        exit(EXIT_FAILURE);
    }
    index_my=0;
    permute(nums,0,numsSize);
    *returnSize=index_my;
    return result;
    
}
