#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N  10000
/**
 * Definition for a binary tree node.*/
 struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
 };
 
int * sortArr;
int index=0;
void inorder(struct TreeNode* root){
	if(root==NULL){
		return ;
	}
	inorder(root->left);
	sortArr[index++]=root->val;
	inorder(root->right);
}
int kthSmallest(struct TreeNode* root, int k) {
    if(root==NULL||k<0){
    	return 0;
	}
	sortArr=(int *)malloc(N*sizeof(int));
	if(sortArr==NULL){
		exit(EXIT_FAILURE);
	}
	index=0;
	inorder(root);
	return sortArr[k-1];
}
