


int findPeakElement(int* nums, int numsSize) {
    if(nums==NULL||numsSize<1){
    	return -1;
	}
	if(numsSize==1){
		return 0;
	}
	//遍历一遍数组来寻找a peak num
	int firstFirst=INT_MIN;
	ine endEnd=INT_MIN;
	for(int i=0;i<numsSize;i++){
		if(i==0&&nums[i]>nums[i+1]||i==numsSize-1&&nums[i]>nums[i-1]){
			return i;
		}
		else{
			if(nums[i-1]<=nums[i]&&nums[i]>=nums[i+1]){
				return i;
			}
		}
	} 
	return -1;
}
