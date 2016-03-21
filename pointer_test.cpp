#include<stdio.h>

int main(){
    int a[5]={1,4,6,9,13};
    int *p;
    int **k;
    p=a;
    k=&p;
    printf("%d",*p);
    printf("%d",*p++);//*p++与*(p++)是等价的 
    printf("%d\n",a[0]);

    printf("%d",(*p)++);//(*p)++是直接输出(*p),然后将p所指向的值+1，即改变a[1]的值 
    printf("%d\n",a[1]);

    printf("%d",*(p++));//先输出p所指向的值，然后指针p+1 
    printf("%d",**k);//随p的指向的改变而改变
    return 0;
}
