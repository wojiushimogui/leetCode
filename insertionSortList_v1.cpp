#include<stdio.h>
#include<stdlib.h>
struct ListNode {
     int val;
     struct ListNode *next;
};
void insertsortArray(int *nums,int numsSize){
	if(nums==NULL||numsSize<=1){
		return;
	}
	for(int i=1;i<numsSize;i++){
		int temp=nums[i];
		int j=i-1;
		for(;j>=0;j--){
			if(temp<nums[j]){
				nums[j+1]=nums[j];
			}
			else if(nums[j]<=temp){
				nums[j+1]=temp;
				break;
			}
		}
		if(j<0){
			nums[0]=temp;
		}
	}
}
#define N  100000
struct ListNode* insertionSortList(struct ListNode* head) {
	if(head==NULL||head->next==NULL){
     	return head;
	 }
	 
	 int *value=(int *)malloc(N*sizeof(int));
	 if(value==NULL){
	 	exit(EXIT_FAILURE);
	 }
	 struct ListNode* cur=head;
	 int index=0;
	 while(cur!=NULL){
	 	value[index++]=cur->val;
	 	cur=cur->next;
	 }
	 //对数组进行插入排序
	 insertsortArray(value,index);
	 //重组为链表
	 head->val=value[0];
	 head->next=NULL;
	 struct ListNode *curNode=head;
	 struct ListNode* node=NULL;
	 for(int i=1;i<index;i++){
	 	node=(struct ListNode*)malloc(sizeof(struct ListNode));
	 	if(node==NULL){
	 		exit(EXIT_FAILURE);
		 }
		 node->val=value[i];
		 node->next=NULL;//注意：这里要设为NULL，否则不能AC，这个bug卡了我好久
		 curNode->next=node;
		 curNode=node;
	 }
	 return head;	 
} 
int main(void){
	int len=6;
	int nums[len]={3,5,1,7,9,1};
	insertsortArray(nums,len);
	for(int i=0;i<len;i++){
		printf("%d  ",nums[i]);
	}
}
