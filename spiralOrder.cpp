#include<stdio.h>
#include<stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//此题比较简单：按圈打印即可
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    if(matrix==NULL||matrixRowSize<1||matrixColSize<1){
        return NULL;
    }
    //nx数组和ny数组用来控制顺时针打印时，下标的变化
    //例如：向右访问时，matrix[y][x]中x每次添加1个单位，y不变；因此nx数组中第一个元素为1，ny数组中第一个元素为0；
    int nx[4]={1,0,-1,0};
    int ny[4]={0,1,0,-1};
    int i=0;//用来控制方向，i=0是表示向右，i=1时表示向下，i=2时表示向左，i=3时表示向上
    int x=-1;
    int y=0;
    //开辟一段空间来保存结果
    int *result=(int *)malloc(matrixRowSize*matrixColSize*sizeof(int));
    if(result==NULL){
        exit(EXIT_FAILURE);
    }
    int index=0;//result的下标
    while(matrixRowSize>0&&matrixColSize>0){
        int k;//用来表示搜索的长度
        if(i%2==0){//即向右、向左搜索时
            k=matrixColSize;
            matrixRowSize--;//搜索一次，行数减一
        }
        else{
            k=matrixRowSize;
            matrixColSize--;
        }
        while(k>0){
            x+=nx[i];
            y+=ny[i];
            result[index]=matrix[y][x];
            k--;
            index++;
            
        }
        i=(i+1)%4;//控制方向
    }
    return result;
}

int main(void){
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF&&m>0&&n>0){
		int **arr=(int **)malloc(m*sizeof(int *));
		if(arr==NULL){
			exit(EXIT_FAILURE);
		}
		for(int i=0;i<m;i++){
			arr[i]=(int *)malloc(n*sizeof(int));
			if(arr[i]==NULL){
				exit(EXIT_FAILURE);
			}
			for(int j=0;j<n;j++){
				scanf("%d",&arr[i][j]);
			}
		}
		int *result=spiralOrder(arr,m,n);
		for(int k=0;k<m*n;k++){
			printf("%d  ",result[k]);
		}
		printf("\n");
	}
	return 0;
}
