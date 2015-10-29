/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
int* twoSum(int* nums, int numsSize, int target) {
    //对于排序过的数组，可以设置头尾指针，如果arr[begin]+arr[end]>target,则end--；如果arr[begin]+arr[end]<target,则begin++；否则返回begin、end
    //实现代码如下
    // int result[2];
    // memset(result,-1,2*sizeof(int));
    // if(nums==NULL||numsSize<2){
    //     return result;
    // }
    // int begin=0;
    // int end=numsSize-1;
    // while(begin<end){
    //     int tempResult=nums[begin]+nums[end];
    //     if(tempResult<target){
    //         begin++;
    //     }
    //     else if(tempResult>target){
    //         end--;
    //     }
    //     else{
    //         result[0]=begin++;
    //         result[1]=end++;
    //         return  result;
    //     }
    // }
    //对于没有排序过的数组，可以先进行排序，然后再按照上面的思路进行求解，但是时间复杂度为O(n*logn)
    //下面采用的方法是：借助一个长度为target的bool  temp[target+1]数组来保存结果。
    //if nums[i]>target,则跳过此数字，否则进行如下判断
    //if temp[nums[i]]为false，则将temp[target-num[i]]设置为true。if temp[num[i]]为true，则说明找到了一种复合条件的情况。
    //值为：index2=i;然后在从前往后开始遍历：寻找target-num[i]在nums中的下标即可。
    //实现如下
    int *result=(int *)malloc(2*sizeof(int));
    if(result==NULL)
    	exit(EXIT_FAILURE); 
    memset(result,0,2*sizeof(int));
    if(nums==NULL||numsSize<2){
        return result;
    }
    //借组一个中间数组
    int *temp=(int *)malloc((target+1)*sizeof(int));
    if(temp==NULL){
        exit(EXIT_FAILURE);
        
    }
    //初始化为 -1 
    memset(temp,-1,(target+1)*sizeof(int));
    int index=0; 
    while(index<numsSize){
    	if(nums[index]>target){
			index++;
			continue; 
		} 
    	else if(temp[nums[index]]==-1){//如果 temp[nums[index]为false，则标记temp[target-nums[index]]为  index
			 temp[target-nums[index]]=index+1; 
		}
		else{//找到第二个数的下标 
			result[1]=index+1;
			result[0]=temp[nums[index]];
			return result;
		}
		
		index++; 
	}
	return result;
	
}
//上面的代码虽然能够正常运行，但是在leetcode中不能提交，还是报“超时”错误。  [0,4,3,0]   0

int main(void){
	int len;
	int target;
	while(scanf("%d %d",&len,&target)!=EOF&&len>1){
		int *nums=(int *)malloc(len*sizeof(int));
		if(nums==NULL){
			exit(EXIT_FAILURE);
		}
		for(int i=0;i<len;i++){
			scanf("%d",nums+i);
		}
		int *result=twoSum(nums, len, target);
		printf("%d  ,  %d\n",result[0],result[1]);
	}
}
