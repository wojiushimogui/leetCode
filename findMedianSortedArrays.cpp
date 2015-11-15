#include<stdio.h>
#include<stdlib.h>

int min(int a,int b){
	return a<=b?a:b;
}

double findKMinNum(int* nums1, int nums1Size, int* nums2, int nums2Size,int k){
	if(nums1Size>nums2Size){//一直保持nums1的长度小于nums2的长度 
		return findKMinNum(nums2,nums2Size,nums1,nums1Size,k) ;
	}
	if(nums1Size==0){
		return nums2[k-1];//数组中的第k个数，下标为k-1. 
	}
	if(k==1){//返回两个数组中最小的那个数字即可
		return min(nums1[0],nums2[0]);
	}
	
	//将k分成两个部分
	int pa=min(nums1Size,k/2);
	int pb=k-pa;
	if(nums1[pa-1]<nums2[pb-1]){//第一种情况：说明nums1中前pa中元素一定是属于前k个最小的数，将其抛弃掉，继续寻找即可。 
		return findKMinNum(nums1+pa,nums1Size-pa,nums2,nums2Size,k-pa) ;
	}
	else if(nums1[pa-1]>nums2[pb-1]){//第二种情况：说明nums2中前pb中元素一定是属于前k个最小的数，将其抛弃掉，继续寻找即可。
		return findKMinNum(nums1,nums1Size,nums2+pb,nums2Size-pb,k-pb);
	}
	else{//第三种情况：说明这两个数就是我们要寻找的第k个最小的数 
		return nums1[k/2];
	}	
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	if(nums1==NULL&&nums2==NULL){
		return 0;
	}
	int total=(nums1Size+nums2Size);
	int k=(total>>1)+1; 
	if(total%2==1){//为奇数,直接返回第K个数即可
		 
		return findKMinNum(nums1,nums1Size,nums2,nums2Size,k) ;
	}
	else{
		return (findKMinNum(nums1,nums1Size,nums2,nums2Size,k-1)+findKMinNum(nums1,nums1Size,nums2,nums2Size,k))/2 ;
	}

} 
