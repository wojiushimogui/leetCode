
#include<stdio.h>
#include<stdlib.h>

/*
˼·��������Ŀ��ʱ�临�Ӷ�����ȷ��Ҫ��Ϊlog(m+n),��ˣ����ǲ��ܲ����Ƚ���������������ϳ�һ������Ȼ���ҳ���λ��
���ǣ����ǿ��Խ�ԭ����ת���һ��Ѱ�ҵ�kС�������⣨��������ԭ�����������У���������λ��ʵ������
��(m+n)/2С����������ֻҪ����˵�kС�������⣬ԭ����Ҳ���Խ����
����������merge��˼��������Ѱ�ҵ�kС��������Ϊ�߽�����̫�࣬���ܽ�����⡣ 
*/

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if(nums1==NULL||nums1Size<1||nums2==NULL||nums2Size<1){
        return 0;
    }
    //������ָ�����ֱ�ָ���������飬������Ѱ����С�ĵ�k=(m+n)/2����
    int *p1=nums1;
    int *p2=nums2;
    int k=(nums1Size+nums2Size)/2;
    int len1=nums1Size;
    int len2=nums2Size;
    bool flag=false;//������ʶ����(m+n)/2����С������ָ������һ����
    while(k>0&&len1>0&&len2>0){
        if((*p1)<=(*p2)){
            p1++;
            len1--;
            flag=true;
        }
        else{
            p2++;
            len2--;
            flag=false;
        }
        k--;
    }
    if(k==0){
        if(len1>0&&len2>0){
            int *fianlPoint=flag?p1:p2;
            return (nums1Size+nums2Size)%2==1?(*p1):((*p1)+(*p2))/2;//������m+n�Ƿ�Ϊ������ż�������⡣
        }
        else{//len=0����һ�������ָ���Ѿ�ָ�������һ��Ԫ�ص���һ��
            int *p=(len1==0)?p2:p1;
            int *pre=(len1==0)?p1-1:p2-1;
            return  (nums1Size+nums2Size)%2==1?(*p):((*p)+(*pre))/2;//������m+n�Ƿ�Ϊ������ż�������⡣
        }
        
        
    }
    // else if(k==1){//˵����ĳһ�������С������һ��������
    //     int *finalPoint=(len1>0)p1:p2;
        
    // }
    else{
        if(len1>0){
            p1+=k;
            return  (nums1Size+nums2Size)%2==1?(*p1):((*p1)+(*(p1-1)))/2;//������m+n�Ƿ�Ϊ������ż�������⡣
        }
        if(len2>0){
            p2+=k;
            return  (nums1Size+nums2Size)%2==1?(*p2):((*p2)+(*(p2-1)))/2;//������m+n�Ƿ�Ϊ������ż�������⡣
        }
        
    }
}

int main(void){
	
	return 0;
}
