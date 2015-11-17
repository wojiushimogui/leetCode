

bool canJump(int* nums, int numsSize) {
    if(nums==NULL||numsSize<1){
    	return false;
	}
	
	if(nums[0]>=numsSize-1){
		return true;
	}
	if(numsSize>1&&nums[0]==0){
		return false;
	}
	int j=0;
	for(;j<numsSize;j++){//如果有某个元素能够直接到。 
		if(nums[j]>=numsSize-j-1){
			result= canJump(nums,j+1);
			if(result){
				return true;
			}
		}
	}
	
	
	return false;	
}
