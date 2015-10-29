/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
int* twoSum(int* nums, int numsSize, int target) {
    //��������������飬��������ͷβָ�룬���arr[begin]+arr[end]>target,��end--�����arr[begin]+arr[end]<target,��begin++�����򷵻�begin��end
    //ʵ�ִ�������
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
    //����û������������飬�����Ƚ�������Ȼ���ٰ��������˼·������⣬����ʱ�临�Ӷ�ΪO(n*logn)
    //������õķ����ǣ�����һ������Ϊtarget��bool  temp[target+1]��������������
    //if nums[i]>target,�����������֣�������������ж�
    //if temp[nums[i]]Ϊfalse����temp[target-num[i]]����Ϊtrue��if temp[num[i]]Ϊtrue����˵���ҵ���һ�ָ��������������
    //ֵΪ��index2=i;Ȼ���ڴ�ǰ����ʼ������Ѱ��target-num[i]��nums�е��±꼴�ɡ�
    //ʵ������
    int *result=(int *)malloc(2*sizeof(int));
    if(result==NULL)
    	exit(EXIT_FAILURE); 
    memset(result,0,2*sizeof(int));
    if(nums==NULL||numsSize<2){
        return result;
    }
    //����һ���м�����
    int *temp=(int *)malloc((target+1)*sizeof(int));
    if(temp==NULL){
        exit(EXIT_FAILURE);
        
    }
    //��ʼ��Ϊ -1 
    memset(temp,-1,(target+1)*sizeof(int));
    int index=0; 
    while(index<numsSize){
    	if(nums[index]>target){
			index++;
			continue; 
		} 
    	else if(temp[nums[index]]==-1){//��� temp[nums[index]Ϊfalse������temp[target-nums[index]]Ϊ  index
			 temp[target-nums[index]]=index+1; 
		}
		else{//�ҵ��ڶ��������±� 
			result[1]=index+1;
			result[0]=temp[nums[index]];
			return result;
		}
		
		index++; 
	}
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
