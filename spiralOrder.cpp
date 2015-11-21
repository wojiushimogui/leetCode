#include<stdio.h>
#include<stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//����Ƚϼ򵥣���Ȧ��ӡ����
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    if(matrix==NULL||matrixRowSize<1||matrixColSize<1){
        return NULL;
    }
    //nx�����ny������������˳ʱ���ӡʱ���±�ı仯
    //���磺���ҷ���ʱ��matrix[y][x]��xÿ�����1����λ��y���䣻���nx�����е�һ��Ԫ��Ϊ1��ny�����е�һ��Ԫ��Ϊ0��
    int nx[4]={1,0,-1,0};
    int ny[4]={0,1,0,-1};
    int i=0;//�������Ʒ���i=0�Ǳ�ʾ���ң�i=1ʱ��ʾ���£�i=2ʱ��ʾ����i=3ʱ��ʾ����
    int x=-1;
    int y=0;
    //����һ�οռ���������
    int *result=(int *)malloc(matrixRowSize*matrixColSize*sizeof(int));
    if(result==NULL){
        exit(EXIT_FAILURE);
    }
    int index=0;//result���±�
    while(matrixRowSize>0&&matrixColSize>0){
        int k;//������ʾ�����ĳ���
        if(i%2==0){//�����ҡ���������ʱ
            k=matrixColSize;
            matrixRowSize--;//����һ�Σ�������һ
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
        i=(i+1)%4;//���Ʒ���
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
