#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int cmp(const void *a,const void *b){
	return ( (*((int *)a))- (*((int *)b)));
}

int threeSumClosest(int* nums, int numsSize, int target) {
    if(nums==NULL||numsSize<3){//��Ч�Լ��
        return 0;
    }
    //�ȶ�nums��������Ȼ���������sorted  array ����2Sum�ķ����������
    int min_dif=INT_MAX;
	qsort(nums,numsSize,sizeof(nums[0]),cmp); 
	for(int i=0;i<numsSize;i++){
		int begin=i+1;
		int end=numsSize-1;
		
		while(begin<end){//������2Sum�ķ���
			int dif=nums[i]+nums[begin]+nums[end]-target;
			if(dif==0){//�ҵ���ȷ�����
				return target; 
				
			} 
			else{
				if(abs(dif)<abs(min_dif)){
					min_dif=dif;
				}
				//ͨ��dif�ķ����ڸı�begin��end��ʹ������ӱƽ���target 
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
