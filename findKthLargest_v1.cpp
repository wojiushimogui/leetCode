
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int* nums, int start,int end){
	if(end<start){
		return -1;
	}
	int val=nums[start];
	int index=start;
	for(int i=start+1;i<=end;i++){
		if(nums[i]<val){
			index++;
			swap(&nums[index],&nums[i]);
		}
	}
	swap(&nums[start],&nums[index]);
	return index;
}

void sortHelper(int* nums, int start,int end,int numsSize,int k){
	if(end<=start){
		return;
	}
	int index=partition(nums,start,end);
	if(index==numsSize-k){
		return;
	}
	else if(index<numsSize-k){
		sortHelper(nums,index+1,end);
	}
	else if(index>numsSize-k){
		sortHelper(nums,start,index-1);
	}
}

int findKthLargest(int* nums, int numsSize, int k) { 
	if(nums==NULL||numsSize<1||k<0||k>numsSize){
    	return 0;
	} 
	int start=0;
	int end=numsSize-1;
	sortHelper(nums,start,end,numsSize,k);
	return nums[numsSize-k];
}
