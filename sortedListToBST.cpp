#include<stdio.h>
#include<stdlib.h>
/*
˼·�������ϸ����˼·�������Ƚ�������ת��Ϊ��������飬Ȼ�������һ����ĺ�������� 
*/
struct TreeNode* sortedArrayToBSTHelper(int* nums, int start,int end){
	if(nums==NULL||end<start){
		return NULL;
	}
	struct TreeNode* node=(struct TreeNode*)malloc(sizeof(struct TreeNode));
	if(node==NULL){
		exit(EXIT_FAILURE);
	}
	int mid=(start+end)/2;
	node->val=nums[mid];
	//ע��������������������Ӧ��������±�߽� 
	node->left=sortedArrayToBSTHelper(nums,start,mid-1);
	node->right=sortedArrayToBSTHelper(nums,mid+1,end);
	return node;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if(nums==NULL||numsSize<=0){
    	return NULL;
	} 
	int start=0;
	int end=numsSize-1;
	return sortedArrayToBSTHelper(nums,start,end);
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    //��һ�����Ƚ���������ת��Ϊ��������
	int nums[1000];
	struct ListNode* cur=head;
	int index=0;
	while(cur!=NULL){
		nums[index++]=cur->val;
		cur=cur->next;
	} 
	return sortedArrayToBST(nums,0,index-1);
}
