int findMin(int* nums, int numsSize) {
    if(nums==NULL||numsSize<1){
    	return 0;
	}
	int minRes=nums[0];
	for(int i=1;i<numsSize;i++){		
		if(nums[i]<minRes){
			minRes=nums[i];
		}
	}
	return minRes;
}
