


/*
�õݹ��˼������
�Ӻ�ʼ���������ҵ���һ���ܹ��������λ�õ��±�index��
Ȼ��ݹ鵽ǰ���Ԫ���ܲ��ܹ�index��λ��
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


