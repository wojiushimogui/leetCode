




int findPeakElement(int* nums, int numsSize) {
    if(nums==NULL||numsSize<1){
    	return -1;
	}
	int left=0;
	int right=numsSize-1;
	while(left<right){
		//不能这样写 int mid=left+(right-left)>>1;因为算术云算法的优先级大于 移位运算符 
		int mid=left+((right-left)>>1);
		if(nums[mid]<nums[mid+1]){
			left=mid+1;
		}
		else{
			right=mid;
		}
	}
	return right;	
}
