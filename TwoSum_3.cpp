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
	
//    ��������������飬��������ͷβָ�룬���arr[begin]+arr[end]>target,��end--�����arr[begin]+arr[end]<target,��begin++�����򷵻�begin��end
//    ʵ�ִ�������

     
     //�ȶ������������
     int *arr=(int *)malloc(numsSize*sizeof(int));
     if(arr==NULL){
     	exit(EXIT_FAILURE);
	 }
	 for(int i=0;i<numsSize;i++){
	 	arr[i]=nums[i];
	 }
	qsort(arr,numsSize,sizeof(nums[0]),cmp); 
	//�����Ź��������arr���ҳ��������� 
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
     //Ȼ�����һ���ҳ�����������ԭ������nums������
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
	 //�ڶԸ�����������󣬻ᵼ�µ�һ�������������ڵڶ����������� 
	 //��result��������С����ǰ������ں�
	 if(result[0]>result[1]){
	 	swap(result,result+1); 
	 }
	 
	 free(arr);
	 arr=NULL;
  	 return result;
     
   
}
//����Ĵ�����Ȼ�ܹ��������У�������leetcode�в����ύ�����Ǳ�����ʱ������  [0,4,3,0]   0

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
