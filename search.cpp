#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


//��Ŀ���⣺�ҳ�target��������num��ת�õ�ʱ����ת��
//˼·������һ�����鼴�� 
//����Ŀ������ 
int search(int* nums, int numsSize, int target) {
    if(nums==NULL||numsSize<1){
    	return -1;
	} 
	int result=-1;
	bool flag=false;//��־�Ƿ�ƥ��
	int bitHigh=target/pow(10,numsSize-1);//���λ 
	int i=0; 
	for(;i<numsSize;i++){//���ҵ����λ�������е�λ�� 
		if(nums[i]==bitHigh){
			break;
		} 
	}
	//��ͨ��һ��forѭ������target���������Ƿ���nums�е���ƥ��
	for(int j=i;j<i+numsSize;j++){
		bitHigh=target/pow(10,numsSize-(j-i+1));//���λ 
		if(bitHigh!=nums[j%numsSize]){//��������������˵����ƥ�� 
			flag=true;
			break;
		}
		//����target 
		target=target%(int)(pow(10,numsSize-(j-i+1)));		
	} 
	if(flag){
		return -1;
	} 
	return i;
}
