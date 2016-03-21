#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void* a,const void* b){
	return ((*(int*)a)-(*(int*)b));
}
int main(void){
	int n;
	int l;
	while(scanf("%d %d",&n,&l)!=EOF){
		if(0<n&&n<=1000&&0<l&&l<=1e9){
			int *a=(int *)malloc(n*sizeof(int));
			if(a==NULL){
				exit(EXIT_FAILURE);
			}
			int k=0;
			for(int i=0;i<n;i++){
				scanf("%d",a+i);
				k++;
				if(a[i]>l||a[i]<0){
					break;
				}
			}
			if(k!=n){
				continue;
			}
			//找出数组a中的最大间隔
			qsort(a,n,sizeof(a[0]),cmp); 
//			for(int i=0;i<n;i++){
//				printf("%d  ",a[i]);
//			}
//			printf("\n");
			int  max=-1;
			for(int i=0;i<n-1;i++){
				int temp=a[i+1]-a[i];
				if(temp>max){
					max=temp;
				}
			}
			float res=max*1.0/2;
			printf("%.2f\n",res);
		}
	}
}
