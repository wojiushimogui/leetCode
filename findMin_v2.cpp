/*
根据题意可知，旋转数组是根据一个排序数组旋转k为而来。
根据这个特征，只需要找到第一个后面的元素小于前面的相邻元素即为最小数；
但是有一点需要注意：如果k=0；则第一个数就是最小数 
*/

int findMin(int* nums, int numsSize) {
    if(nums==NULL||numsSize<1){
    	return 0;
	}
	int minRes=nums[0];
	for(int i=1;i<numsSize;i++){		
		if(nums[i+1]<nums[i]){
			return nums[i+1];
		} 
	}
	return minRes;
}
