#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int cmp(const void *a,const void *b){
	return ( (*((int *)a))- (*((int *)b)));
}

int threeSumClosest(int* nums, int numsSize, int target) {
    if(nums==NULL||numsSize<3){//有效性检查
        return 0;
    }
    //先对nums进行排序，然后借助于在sorted  array 中求2Sum的方法进行求解
    int min_dif=INT_MAX;
	qsort(nums,numsSize,sizeof(nums[0]),cmp); 
	for(int i=0;i<numsSize;i++){
		int begin=i+1;
		int end=numsSize-1;
		
		while(begin<end){//借助于2Sum的方法
			int dif=nums[i]+nums[begin]+nums[end]-target;
			if(dif==0){//找到精确的组合
				return target; 
				
			} 
			else{
				if(abs(dif)<abs(min_dif)){
					min_dif=dif;
				}
				//通过dif的符号在改变begin和end，使结果更加逼近与target 
				if(dif<0){//increase value
					begin++;
				}
				else{//decrease value
					end--;
				}
			}
			
		}
	}
	return min_dif+target; 

}

int main(void){
	int k;
	int target;
	while(scanf("%d  %d",&k,&target)!=EOF&&k>=3){
		int *nums=(int *)malloc(k*sizeof(int));
		for(int i=0;i<k;i++){
			scanf("%d",nums+i);
		}
		int result=threeSumClosest(nums,k,target);
		printf("%d\n",result);
	}
}
