#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE  1000
int g_index=0;
int g_totalLen=0;
int g_minIndex=-1; 
int g_minValue=INT_MAX;
MinStack *g_stack=NULL;
typedef struct {
    int val;
} MinStack;

void minStackCreate(MinStack *stack, int maxSize) {
    if(maxSize<1){
    	return;
	} 
	stack=(MinStack *)malloc(maxSize*sizeof(MinStack));
	if(stack==NULL){
		exit(EXIT_FAILURE);
	}
	g_index=0;
	g_totalLen=maxSize;
}

void minStackPush(MinStack *stack, int element) {
	if(stack==NULL){//����һ��ջ
		minStackCreate(stack,MAXSIZE);
	}
	if(element<g_minValue){//������Сֵ��λ�� 
		g_minIndex=g_index;
		g_minValue=element;
	}
	if(g_index<g_totalLen){
		stack[g_index].val=element;
		g_index++;
		
	}
	else{//����һ��2* maxSize��ջ 
		MinStack *newstack=NULL;
		int len=g_totalLen;
		minStackCreate(newstack, g_totalLen*2);
		//��stack�е�Ԫ�ؿ�����newStack
		int i=0;
		for(;i<len;i++){
			newstack[i]=stack[i];
		} 
		stack=newstack;
		stack[len].val=element;
		g_index=len+1;
	}   
}

void minStackPop(MinStack *stack) {
    if(stack==NULL||g_index<=0){
    	return;
	}
	else{
		g_index--;
		//�������Сֵ����ȥ�ˣ��������ҵ���Сֵ��λ��
		if(g_minIndex==g_index){
			g_minValue=INT_MAX;
			for(int i=0;i<g_index;i++){
				if(stack[i].val<g_minValue){
					g_minValue=stack[i].val;
					g_minIndex=i;
				}
			}
		} 
	}		
}

int minStackTop(MinStack *stack) {
    if(stack==NULL||g_index<=0){
    	return -1;
	}
	else{		
		return stack[g_index-1].val;
	}
}

int minStackGetMin(MinStack *stack) {
    if(stack==NULL||g_index<=0){//ջ����û��Ԫ�ص� 
    	return 0;
	}
	return g_minValue;	
}

void minStackDestroy(MinStack *stack) {
    if(stack==NULL){
    	return;
	}
	free(stack);
	stack==NULL;	
}

int main(void){
	MinStack *stack=NULL;
	minStackPush(stack,-3);
	int res=minStackGetMin(stack);
	printf("  %d",res);
}
