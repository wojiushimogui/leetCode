#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
/*
���ö���������Ѱ��Ŀ�� 
*/
int binarysearch(int *nums,int begin,int end,int target){
	if(nums==NULL||(begin>end)){
		return -1;
	} 
	int mid=begin+(end-begin)/2;
	//�������begin/end/mid����target���бȽ� 
	if(nums[mid]==target){
		return mid;
	}
	if(nums[end]==target){
		return end;
	}
	if(nums[begin]==target){
		return begin;
	}
	//��һ�����
	if(nums[end]>nums[begin]){
		if(target<nums[begin]||target>nums[end]){//target���ڴ˷�Χ�� 
			return -1;
		}
	    if(nums[mid]>target){
			end=mid-1;
			return binarysearch(nums,begin,end,target);
		}
		else{
			begin=mid+1;
			return binarysearch(nums,begin,end,target);
		}
	}
	//�ڶ������
	else if(nums[mid]>nums[end]){
		if(nums[mid]>target&&target>nums[begin]){//��mid����� 
			end=mid-1;
			begin=begin+1; 
			return binarysearch(nums,begin,end,target);
		}
		else {//target>nums[mid]��mid���ұ� 
			begin=mid+1;
			end=end-1;//�����ǵڶ��������
			return binarysearch(nums,begin,end,target); 
		}
		
	}
	//��������� 
	else if(nums[mid]<nums[end]){
		if(nums[mid]<target&&target<nums[end]){//��mid�ұ� 
			begin=mid+1;
			end=end-1;
			return binarysearch(nums,begin,end,target); 
			 
		}
		else {//��mid����� 
			end=mid-1;
			begin=begin+1;//�����ʼ�ĵط��Ͱ����˺�midλ�õ�ֵ��target�����˱Ƚ� 
			return  binarysearch(nums,begin,end,target); 
		}
	}
	
}
int search(int* nums, int numsSize, int target) {
    if(nums==NULL||numsSize<1){
    	return -1;
	} 
	int begin=0;
	int end=numsSize-1;
	return binarysearch(nums,begin,end,target);
}
