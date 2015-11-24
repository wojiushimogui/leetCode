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
		if(nums[begin]<nums[end]){//第一种情况
			 if(nums[mid]>target)  end=mid-1;
			 else begin=mid+1;
		}
		else if(nums[mid]>nums[end]){//第二种情况 
			if(nums[mid]>target&&nums[begin]<=target){//在mid左边,注意等号 
				end=mid-1; 
			}
			else{
				begin=mid+1;
			}
		} 
		else{//第三种情况 
			if(nums[mid]<target&&nums[end]>=target){//在mid的右边，注意等号 
				begin=mid+1; 
			}
			else{
				end=mid-1;
			}
		} 
	}
	return -1;
}
