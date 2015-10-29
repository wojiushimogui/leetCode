/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
int  cmp(const void* a,const void *b){
	return (*(int *)a)-(*(int *)b);
}
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
int* twoSum(int* nums, int numsSize, int target) {
	
//    对于排序过的数组，可以设置头尾指针，如果arr[begin]+arr[end]>target,则end--；如果arr[begin]+arr[end]<target,则begin++；否则返回begin、end
//    实现代码如下

     
     //先对数组进行排序
     int *arr=(int *)malloc(numsSize*sizeof(int));
     if(arr==NULL){
     	exit(EXIT_FAILURE);
	 }
	 for(int i=0;i<numsSize;i++){
	 	arr[i]=nums[i];
	 }
	qsort(arr,numsSize,sizeof(nums[0]),cmp); 
	//在已排过序的数组arr中找出这两个数 
     int begin=0;
     int end=numsSize-1;
     while(begin<end){
         int tempResult=arr[begin]+arr[end];
         if(tempResult<target){
             begin++;
         }
         else if(tempResult>target){
             end--;
         }
         else{
            break;
         }
     }
     //然后遍历一次找出这两个数在原数组中nums的索引
     int *result=(int *)malloc(2*sizeof(int));
     memset(result,-1,2*sizeof(int));
     if(nums==NULL||numsSize<2){
         return result;
     }
	 if(begin<end){
		 	for(int i=0;i<numsSize;i++){
			 	if(nums[i]==arr[begin]){
			 		if(result[0]==-1){
			 			result[0]=i+1;
			 			continue;
					 }	
				 }
				 if(nums[i]==arr[end]){
				 	if(result[1]==-1){
			 			result[1]=i+1;
					 }
				 }
		 	} 
		
	 }
	 //在对负数进行排序后，会导致第一个数的索引大于第二个的索引。 
	 //对result进行排序，小的在前，大的在后
	 if(result[0]>result[1]){
	 	swap(result,result+1); 
	 }
	 
	 free(arr);
	 arr=NULL;
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
