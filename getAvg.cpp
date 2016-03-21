#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define M  1e7
int main(void){
	int n,r,avg;
	int *a;
	int *b;
	while(scanf("%d %d %d",&n,&r,&avg)!=EOF){
		if(1<=n&&n<=1e5&&1<=r&&n<=1e9&&1<=avg&&avg<=1e6){
			a=(int *)malloc(n*sizeof(int));
		b=(int *)malloc(n*sizeof(int));
		if(a==NULL||b==NULL){
			exit(EXIT_FAILURE);
		}
		for(int i=0;i<n;i++){
			scanf("%d %d",a+i,b+i);
		}
		int res=0;
		for(int i=0;i<n;i++){
			res+=a[i];
		}
		int total=avg*n;
		if(res>=(total)){
			printf("0\n");
			continue;
		}
		int remain=total-res;
		//每次选取最小
		int* visited=(int *)malloc(n*sizeof(int));
		if(visited==NULL){
			exit(EXIT_FAILURE);
		}
		memset(visited,0,n*sizeof(int));
		int result=0;
		for(int i=0;i<n;i++){
			int min=M;
			int k=-1;
			for(int j=0;j<n;j++){
				if(visited[j]!=1&&b[j]<min){
					min=b[j];
					k=j;
				}
			}
			visited[k]=1;
			int temp=r-a[k];
			if(temp<=remain){
				result+=temp*b[k];
				remain-=temp;
			}
			else if(temp>remain){
				result+=remain*b[k];
				remain-=remain;
			}
			if(remain==0){
				printf("%d\n",result);
				break;
			}
		}
		free(a);
		free(b);
		a=NULL;
		b=NULL;
		}		 
	}
}
