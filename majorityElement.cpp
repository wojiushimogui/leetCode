
int cmp(const void *a,const void *b){
	return  ((*(int*)a)-(*(int*)b));
}

int majorityElement(int* nums, int numsSize) {
    if(nums==NULL||numsSize<1){
    	return 0;
	}
	qsort(nums,numsSize,sizeof(nums[0]),cmp);
	return nums[numsSize/2];
}
