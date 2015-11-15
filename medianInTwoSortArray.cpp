
#include<stdio.h>
#include<stdlib.h>

/*
思路：由于题目对时间复杂度有明确的要求，为log(m+n),因此，我们不能采用先将两个数组排序组合成一个数组然后找出中位数
但是，我们可以将原问题转变成一个寻找第k小数的问题（假设两个原序列升序排列），这样中位数实际上是
第(m+n)/2小的数。所以只要解决了第k小数的问题，原问题也得以解决。
下面是利用merge的思想来进行寻找第k小的数，因为边界条件太多，不能解决问题。 
*/

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if(nums1==NULL||nums1Size<1||nums2==NULL||nums2Size<1){
        return 0;
    }
    //用两个指针量分别指向两个数组，依次来寻找最小的第k=(m+n)/2个数
    int *p1=nums1;
    int *p2=nums2;
    int k=(nums1Size+nums2Size)/2;
    int len1=nums1Size;
    int len2=nums2Size;
    bool flag=false;//用来标识，第(m+n)/2个最小的数的指针是那一个。
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
            return (nums1Size+nums2Size)%2==1?(*p1):((*p1)+(*p2))/2;//考虑了m+n是否为奇数和偶数的问题。
        }
        else{//len=0的那一个数组的指针已经指向了最后一个元素的下一个
            int *p=(len1==0)?p2:p1;
            int *pre=(len1==0)?p1-1:p2-1;
            return  (nums1Size+nums2Size)%2==1?(*p):((*p)+(*pre))/2;//考虑了m+n是否为奇数和偶数的问题。
        }
        
        
    }
    // else if(k==1){//说明有某一个数组较小，在另一个数组中
    //     int *finalPoint=(len1>0)p1:p2;
        
    // }
    else{
        if(len1>0){
            p1+=k;
            return  (nums1Size+nums2Size)%2==1?(*p1):((*p1)+(*(p1-1)))/2;//考虑了m+n是否为奇数和偶数的问题。
        }
        if(len2>0){
            p2+=k;
            return  (nums1Size+nums2Size)%2==1?(*p2):((*p2)+(*(p2-1)))/2;//考虑了m+n是否为奇数和偶数的问题。
        }
        
    }
}

int main(void){
	
	return 0;
}
