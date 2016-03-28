
/*
˼·һ���������������������������˲�����������飬
��������Ŀռ� �����Ҳ���У���Ϊ��ĿҲ������ 
˼·�����ñ�������Ҳ���У�������ʱ�临�Ӷ�С��O(n*n) 
˼·������Դ�ڣ�https://leetcode.com/discuss/89038/o-32-n-solution-using-bit-manipulation-in-10-lines 
We can count the sum of each 32 bits separately 
for the given array (stored in "b" variable) and for the array [1, 2, 3, ..., n] (stored in "a" variable).
 If "b" is greater than "a", it means that duplicated number has 1 at the current bit position 
 (otherwise, "b" couldn't be greater than "a"). This way we retrieve the answer bit by bit: 
*/
int findDuplicate(int* nums, int numsSize) {
    if(nums==NULL||numsSize<1){
    	return -1;
	} 
	int res=0;
	for(int i=0;i<32;i++){
		int bit=1<<i;
		int a=0;
		int b=0;
		for(int j=0;j<numsSize;j++){
			if(j&bit){
				a++;
			}
			if(nums[j]&bit){
				b++;
			}
		}
		if(b>a){
			res+=bit;
		}
	}
	return res;	
}
