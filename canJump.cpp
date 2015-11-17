


/*
用递归的思想来做
从后开始遍历，先找到第一个能够到达最后位置的下标index；
然后递归到前面的元素能不能够index的位置
*/

bool canJump(int* nums, int numsSize) {
    if(nums==NULL||numsSize<1){
    	return false;
	}
	if(numsSize>1&&nums[0]==0){
		return false;
	}
	if(numsSize==1){
		return true;
	}
	int i=numsSize-2;
	bool result=false;
	for(;i>=0;i--){
		if(nums[i]>=numsSize-1-i){
			result= canJump(nums,i+1);
			if(result){
				return true;
			}
		}
	}
	
	return false;	
}

int main(void){
	
}


