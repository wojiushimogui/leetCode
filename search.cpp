#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


//题目大意：找出target是有数组num旋转得到时的旋转轴
//思路：遍历一次数组即可 
//把题目理解错了 
int search(int* nums, int numsSize, int target) {
    if(nums==NULL||numsSize<1){
    	return -1;
	} 
	int result=-1;
	bool flag=false;//标志是否匹配
	int bitHigh=target/pow(10,numsSize-1);//最高位 
	int i=0; 
	for(;i<numsSize;i++){//先找到最高位在数组中的位置 
		if(nums[i]==bitHigh){
			break;
		} 
	}
	//再通过一个for循环看看target的其他数是否与nums中的数匹配
	for(int j=i;j<i+numsSize;j++){
		bitHigh=target/pow(10,numsSize-(j-i+1));//最高位 
		if(bitHigh!=nums[j%numsSize]){//如果满足此条件，说明不匹配 
			flag=true;
			break;
		}
		//更新target 
		target=target%(int)(pow(10,numsSize-(j-i+1)));		
	} 
	if(flag){
		return -1;
	} 
	return i;
}
