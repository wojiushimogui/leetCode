#include<stdio.h>
#include<stdlib.h>


  struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };
/*
思路：将数组以中心点分割为两部分，左边就为该节点的左子树，右边为该节点的右子树 
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

int main(void){
	int nums[2]={1,3};
	sortedArrayToBST(nums,2);
}
