/*
���������֪����ת�����Ǹ���һ������������תkΪ������
�������������ֻ��Ҫ�ҵ���һ�������Ԫ��С��ǰ�������Ԫ�ؼ�Ϊ��С����
������һ����Ҫע�⣺���k=0�����һ����������С�� 
*/

int findMin(int* nums, int numsSize) {
    if(nums==NULL||numsSize<1){
    	return 0;
	}
	int minRes=nums[0];
	for(int i=0;i<numsSize-1;i++){		
		if(nums[i+1]<nums[i]){
			return nums[i+1];
		} 
	}
	return minRes;
}
