
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
˼·��
��һ�����Ӻ�ʼ�������ҵ���һ����������Ԫ�������λ��pos.
�ڶ��������û���ҵ�pos����˵��������һ�����У����䷴�򼴿ɡ�����ҵ���pos��
��Ӻ�ʼ�������ҵ���һ������nums[pos]ֵ��λ��k,Ȼ�󽻻�nums[pos]��nums[k] ��λ��
����������pos֮�������Ԫ�ؽ���һ���������򣩼��� 
*/

int cmp(const void * a,const void *b){
	return (*((int *)a))-(*((int *)b));
}
void nextPermutation(int* nums, int numsSize) {
    if(nums==NULL||numsSize<2){
        return;
    }
    int pos=-1; 
    //��һ�����Ӻ�ʼ�������ҵ���һ����������Ԫ�������λ��pos. 
    for(int i=numsSize-1;i>0;i--){
        if(nums[i]>nums[i-1]){
        	pos=i-1;
        	break;
		}
    }
    if(pos==-1){//˵������ʱ����һ�����У��������򼴿�
		qsort(nums,numsSize,sizeof(nums[0]),cmp); 
		return;   	
	} 
	//�������˵�����ҵ��������λ��
	//�ڶ������Ӻ�ʼ�������ҵ�����һ������nums[pos]��λ��k�������佻��
	for(int i=numsSize-1;i>0;i--){
		if(nums[i]>nums[pos]){
			int temp=nums[i];
			nums[i]=nums[pos];
			nums[pos]=temp;
			break;
		}
	}
	//����������nums�����д��±�pos�Ժ������������
	qsort(nums+pos+1,numsSize-pos-1,sizeof(nums[0]),cmp) ;
	
    
}
