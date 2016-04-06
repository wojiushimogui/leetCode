/*
函数功能：
第start个元素被盗可能产生的最大值 */
int robHelper(int* nums, int numsSize,int start){
	if(nums==NULL||numsSize<1||numsSize<=start){
    	return 0;
	}
	return nums[start]+max(robHelper(nums,numsSize,start+2),robHelper(nums,numsSize,start+3));
}

int rob(int* nums, int numsSize) {  
	int fristElementMax=robHelper(nums,numsSize,0);//第一个元素被盗后产生的最大值 
	int secondElementMax=robHelper(nums,numsSize,1);//第二个元素被盗后可能产生的最大值 
	return fristElementMax>secondElementMax?fristElementMax:secondElementMax;
}
