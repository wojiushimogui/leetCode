#include<stdio.h>

int main(){
    int a[5]={1,4,6,9,13};
    int *p;
    int **k;
    p=a;
    k=&p;
    printf("%d",*p);
    printf("%d",*p++);//*p++��*(p++)�ǵȼ۵� 
    printf("%d\n",a[0]);

    printf("%d",(*p)++);//(*p)++��ֱ�����(*p),Ȼ��p��ָ���ֵ+1�����ı�a[1]��ֵ 
    printf("%d\n",a[1]);

    printf("%d",*(p++));//�����p��ָ���ֵ��Ȼ��ָ��p+1 
    printf("%d",**k);//��p��ָ��ĸı���ı�
    return 0;
}
