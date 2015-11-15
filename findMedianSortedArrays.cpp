#include<stdio.h>
#include<stdlib.h>

int min(int a,int b){
	return a<=b?a:b;
}

double findKMinNum(int* nums1, int nums1Size, int* nums2, int nums2Size,int k){
	if(nums1Size>nums2Size){//һֱ����nums1�ĳ���С��nums2�ĳ��� 
		return findKMinNum(nums2,nums2Size,nums1,nums1Size,k) ;
	}
	if(nums1Size==0){
		return nums2[k-1];//�����еĵ�k�������±�Ϊk-1. 
	}
	if(k==1){//����������������С���Ǹ����ּ���
		return min(nums1[0],nums2[0]);
	}
	
	//��k�ֳ���������
	int pa=min(nums1Size,k/2);
	int pb=k-pa;
	if(nums1[pa-1]<nums2[pb-1]){//��һ�������˵��nums1��ǰpa��Ԫ��һ��������ǰk����С����������������������Ѱ�Ҽ��ɡ� 
		return findKMinNum(nums1+pa,nums1Size-pa,nums2,nums2Size,k-pa) ;
	}
	else if(nums1[pa-1]>nums2[pb-1]){//�ڶ��������˵��nums2��ǰpb��Ԫ��һ��������ǰk����С����������������������Ѱ�Ҽ��ɡ�
		return findKMinNum(nums1,nums1Size,nums2+pb,nums2Size-pb,k-pb);
	}
	else{//�����������˵������������������ҪѰ�ҵĵ�k����С���� 
		return nums1[k/2];
	}	
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	if(nums1==NULL&&nums2==NULL){
		return 0;
	}
	int total=(nums1Size+nums2Size);
	int k=(total>>1)+1; 
	if(total%2==1){//Ϊ����,ֱ�ӷ��ص�K��������
		 
		return findKMinNum(nums1,nums1Size,nums2,nums2Size,k) ;
	}
	else{
		return (findKMinNum(nums1,nums1Size,nums2,nums2Size,k-1)+findKMinNum(nums1,nums1Size,nums2,nums2Size,k))/2 ;
	}

} 
