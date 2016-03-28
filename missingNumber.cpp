

int missingNumber(int* nums, int numsSize) {
    if(nums==NULL||numsSize<1){
    	return -1;
	}
	int arrSum=0;
	int totalSum=0;
	for(int i=0;i<numsSize;i++){
		arrSum+=nums[i];
		totalSum+=(i+1);
	}
	return totalSum-arrSum;
}
