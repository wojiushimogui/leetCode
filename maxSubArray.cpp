

int maxSubArray(int* nums, int numsSize) {
    if(nums==NULL||numsSize<1){
    	return 0;
	}
	int max=nums[0];//用来保存最大值。
//	int begin=0;
//	int end=0;
	int tempSum=0;
	for(int i=0;i<numsSize;i++){
		tempSum+=nums[i];
		if(tempSum>max){
			max=tempSum;
		}
		if(tempSum<0){
		//	begin=i+1;
			tempSum=0;
			continue;
		}
	}
	return max;   
}
