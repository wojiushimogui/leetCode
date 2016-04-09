
int cmp(const void* a,const void* b){
	return  (*((int *)a))-(*((int *)b));
}

int findKthLargest(int* nums, int numsSize, int k) {
    if(nums==NULL||numsSize<1||k<0||k>numsSize){
    	return 0;
	}
	qsort(nums,numsSize,sizeof(nums[0]),cmp);
	return nums[numsSize-k];
}
