#include<stdio.h>
#include<stdlib.h>
#include<string.h>

bool search(int* nums, int numsSize, int target) {
    if(nums==NULL||numsSize<1){
        return false;
    }
    int begin=0;
    int end=numsSize-1;
    while(begin<end){
    	int mid=begin+(end-begin)/2;
    	if(nums[mid]==target){
    		return true;
		}
		//以下只比较nums[mid]与nums[end]的大小来控制end和begin的变化 
		if(nums[mid]<nums[end]){
			if(target>nums[mid]&&target<=nums[end])  begin=mid+1;
			else end=mid-1;
		}
		else if(nums[mid]>nums[end]){
			if(target>=nums[begin]&&target<nums[mid]) end=mid-1;
			else begin=mid+1;
		}
		else{
			end--;
		}
	}
	return false;
}
