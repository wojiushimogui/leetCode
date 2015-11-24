#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


int search(int* nums, int numsSize, int target) {
    if(nums==NULL||numsSize<1){
    	return -1;
	} 
	int begin=0;
	int end=numsSize-1;
	while(begin<=end){
		int mid=begin+(end-begin)/2;
		if(nums[mid]==target)  return mid;
		if(nums[begin]<nums[end]){//��һ�����
			 if(nums[mid]>target)  end=mid-1;
			 else begin=mid+1;
		}
		else if(nums[mid]>nums[end]){//�ڶ������ 
			if(nums[mid]>target&&nums[begin]<=target){//��mid���,ע��Ⱥ� 
				end=mid-1; 
			}
			else{
				begin=mid+1;
			}
		} 
		else{//��������� 
			if(nums[mid]<target&&nums[end]>=target){//��mid���ұߣ�ע��Ⱥ� 
				begin=mid+1; 
			}
			else{
				end=mid-1;
			}
		} 
	}
	return -1;
}
