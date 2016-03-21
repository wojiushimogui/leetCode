

#include<stdio.h>
#include<stdlib.h>
#include<math.h> 
int dis(int x1,int y1,int x0,int y0){
	return (x1-x0)^2+(y1-y0)^2;
}
int main(void){
	int R;
	int x1,y1,x2,y2,x3,y3,x0,y0;
	
	while(scanf("%d,%d,%d,%d,%d,%d,%d,%d,%d",&R,&x1,&y1,&x2,&y2,&x3,&y3,&x0,&y0)!=EOF){
//		scanf("%d,%d,%d,%d,%d,%d,%d,%d,%d",&R,&x1,&y1,&x2,&y2,&x3,&y3,&x0,&y0);
		if(R<0||x0<0||y0<0||x1<0||y1<0||x2<0||y2<0){
			printf("0x");
		}
		int res=0;
		int disValue=R*R;
		if(dis(x1,y1,x0,y0)<=disValue){
			res++;
		}
		if(dis(x2,y2,x0,y0)<=disValue){
			res++;
		}
		if(dis(x3,y3,x0,y0)<=disValue){
			res++;
		}
		printf("%dx",res);
	}
}
