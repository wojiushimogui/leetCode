#include<stdio.h>
#include<stdlib.h>
/*
思路：根据上个题的思路，可以先将此链表转换为排序的数组，然后调用上一个题的函数来完成 
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
	//注意左子树和右子树所对应的数组的下标边界 
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
    //第一步：先将排序链表转换为排序数组
	int nums[1000];
	struct ListNode* cur=head;
	int index=0;
	while(cur!=NULL){
		nums[index++]=cur->val;
		cur=cur->next;
	} 
	return sortedArrayToBST(nums,0,index-1);
}
