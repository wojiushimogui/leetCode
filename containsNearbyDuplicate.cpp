bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
	if(nums==NULL||numsSize<2){
		return false;
	}    
	for(int i=0;i<numsSize-1;i++){
		int temp=nums[i];
		int count=0;
		for(int j=i+1;j<numsSize;j++){
		    count++;
		    
			if(temp==nums[j]&&count<=k){//ע�⣺����Ϊk����j-i<=k;����i��j���˶������ȥ
				return true;
			}
			if(count>=k){
		        break;
		    }
		}
	}
	return false;
}
