/*
�������ܣ�
��start��Ԫ�ر������ܲ��������ֵ */
int robHelper(int* nums, int numsSize,int start){
	if(nums==NULL||numsSize<1||numsSize<=start){
    	return 0;
	}
	return nums[start]+max(robHelper(nums,numsSize,start+2),robHelper(nums,numsSize,start+3));
}

int rob(int* nums, int numsSize) {  
	int fristElementMax=robHelper(nums,numsSize,0);//��һ��Ԫ�ر�������������ֵ 
	int secondElementMax=robHelper(nums,numsSize,1);//�ڶ���Ԫ�ر�������ܲ��������ֵ 
	return fristElementMax>secondElementMax?fristElementMax:secondElementMax;
}
