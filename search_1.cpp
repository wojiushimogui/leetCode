

int search(int* nums, int numsSize, int target) {
    if(nums==NULL||numsSize<1){
    	return -1;
	} 
	bool flag=false;//��־�Ƿ�ƥ��
	int i=0; 
	for(;i<numsSize;i++){//���ҵ����λ�������е�λ�� 
		if(nums[i]==target){
			break;
		} 
	}
	
	return i;
}
