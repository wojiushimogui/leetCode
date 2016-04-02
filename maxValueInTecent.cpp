#include<stdio.h>
#include<stdlib.h>
/*
 用递归来完成 
*/
int max(int a,int b){
	return a>b?a:b;
} 
int maxValueHelper(int **arr,int rowSize,int colSize,int rowIndex,int colIndex){
	//先进行有效性检查 
	if(arr==NULL||rowSize<1||colSize<1||rowIndex<0||rowSize<=rowIndex||colIndex<0||colSize<=colIndex){
		return 0;
	}	
	int maxValueInDown=arr[rowIndex][colIndex]+maxValueHelper(arr,rowSize,colSize,rowIndex,colIndex+1);
	int maxValueInRight=arr[rowIndex][colIndex]+maxValueHelper(arr,rowSize,colSize,rowIndex+1,colIndex);
	return  max(maxValueInDown,maxValueInRight);
	
}

int maxValue(int **arr,int rowSize,int colSize){
	return maxValueHelper(arr,rowSize,colSize,0,0); 
}
int main(void){
	int m,n;
	while(scanf("%d %d",&m,&n)!=EOF&&0<m&&m<=1000&&0<n&&n<=1000){
		int **arr=(int **)malloc(m*sizeof(int *));
		if(arr==NULL){
			printf("malloc fail\n");
			return -1;
		}
		//输入数据 
		int i=0;
		for(;i<m;i++){
			arr[i]=(int *)malloc(n*sizeof(int));
			if(arr[i]==NULL){
				printf("malloc fail\n");
				return -1;
			}
			int j=0;
			for(;j<n;j++){
				scanf("%d",&arr[i][j]);
			}
		}
		int res=maxValue(arr,m,n); 
		printf("%d\n",res);
	}
	return 0;
}
