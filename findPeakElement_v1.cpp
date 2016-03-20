




int findPeakElement(int* nums, int numsSize) {
    if(nums==NULL||numsSize<1){
    	return -1;
	}
	int left=0;
	int right=numsSize-1;
	while(left<right){
		//��������д int mid=left+(right-left)>>1;��Ϊ�������㷨�����ȼ����� ��λ����� 
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
