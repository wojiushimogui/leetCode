

int search(int* nums, int numsSize, int target) {
    if(nums==NULL||numsSize<1){
    	return -1;
	} 
	bool flag=false;//标志是否匹配
	int i=0; 
	for(;i<numsSize;i++){//先找到最高位在数组中的位置 
		if(nums[i]==target){
			break;
		} 
	}
	
	return i;
}
