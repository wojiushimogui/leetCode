
/*
The ideas is simple ,using some greedy tactics.

We generally maintain a start position to indicate the current position,and there are only 2 main steps for solving the problem.

step(1): When you are at position start, you can go to positon start + 1 to start + nums[start] if nums[start] > 0, 
and now you can know whether you can go to the end by judging nums[start] >= nums.size()-1.
If so, go to step(3). If not, go to step(2).

step(2): From start + 1 to start + nums[start], in these nums[start] positions,pick one to be the next start position. 
And the rule for picking is simple:

You pick a position start + i, from which you can move forward the longest distance,
which means i + nums[start + i] >= j + nums[start + j] for any 1 <= j <= nums[start].

So the start position is at start + i now. Then you go to the step(1).

step(3): Return the answer.
*/
int count;
void minJump(int *nums,int numsSize,int start){
	if(nums==NULL||numsSize<1){
    	return 0;
	}
	count++;
	int end=start+nums[start];
	if(end>=numsSize-1){
		return ;
	}
	int max=0;
	int index=0; 
	for(int i=start+1;i<=end;i++){//寻找在这个区间中，离目标最近的那个点 
		if(i+nums[i]>max){
			index=i;
			max=i+nums[i];
		}
	}
	minJump(nums,numsSize,index);//起点换了 
	
	
}

int jump(int* nums, int numsSize) {
    if(nums==NULL||numsSize<1){
    	return 0;
	}
	if(numsSize==1){//一个元素
	    return 0;
	}
	count=0;
    minJump(nums,numsSize,0);
    return count;
    
}
