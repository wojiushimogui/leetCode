

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
	int i=nums[0];
	
	bool result=false;
	for(;i>0;i--){
		if(nums[i]>0){
			result=canJump(nums+i,numsSize-i);
			if(result){
				return true;
			}
		}
	}
//	int i=numsSize-2;
//	bool result=false;
//	for(;i>=0;i--){
//		if(nums[i]>=numsSize-1-i){
//			result= canJump(nums,i+1);
//			if(result){
//				return true;
//			}
//		}
//	}
	
	return false;	
}
