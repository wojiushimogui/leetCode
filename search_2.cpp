#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
/*
利用二分搜索来寻找目标 
*/
int binarysearch(int *nums,int begin,int end,int target){
	if(nums==NULL||(begin>end)){
		return -1;
	} 
	int mid=begin+(end-begin)/2;
	//将数组的begin/end/mid都与target进行比较 
	if(nums[mid]==target){
		return mid;
	}
	if(nums[end]==target){
		return end;
	}
	if(nums[begin]==target){
		return begin;
	}
	//第一种情况
	if(nums[end]>nums[begin]){
		if(target<nums[begin]||target>nums[end]){//target不在此范围中 
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
	//第二种情况
	else if(nums[mid]>nums[end]){
		if(nums[mid]>target&&target>nums[begin]){//在mid的左边 
			end=mid-1;
			begin=begin+1; 
			return binarysearch(nums,begin,end,target);
		}
		else {//target>nums[mid]在mid的右边 
			begin=mid+1;
			end=end-1;//由于是第二种情况，
			return binarysearch(nums,begin,end,target); 
		}
		
	}
	//第三种情况 
	else if(nums[mid]<nums[end]){
		if(nums[mid]<target&&target<nums[end]){//在mid右边 
			begin=mid+1;
			end=end-1;
			return binarysearch(nums,begin,end,target); 
			 
		}
		else {//在mid的左边 
			end=mid-1;
			begin=begin+1;//由于最开始的地方就把两端和mid位置的值与target进行了比较 
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
