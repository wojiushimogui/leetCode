#include<stdio.h>
#include<stdlib.h> 

struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
};
/*
思路：先求出此二叉树的前序遍历，然后进行构建 
*/
#define N  1000
void getPreOrder(struct TreeNode* root,int *treeNodePreOrder,int* index){
	if(root==NULL){
		return;
	}
	treeNodePreOrder[(*index)]=root->val;
	(*index)++;
	getPreOrder(root->left,treeNodePreOrder,index);
	getPreOrder(root->right,treeNodePreOrder,index);	
}
void flatten(struct TreeNode* root) {
	if(root==NULL){
		return;
	}
    //第一步：求出二叉树的前序遍历
    int treeNodePreOrder[N];   
    int index=0;
	getPreOrder(root,treeNodePreOrder,&index); 
	//第二步：进行构建
	struct TreeNode* cur=root;
	cur->left=NULL;
	for(int i=1;i<index;i++){
		struct TreeNode *node=(struct TreeNode *)malloc(sizeof(struct TreeNode));
		if(node==NULL){
			exit(EXIT_FAILURE);
		}
		node->val=treeNodePreOrder[i];
		node->left=NULL;
		node->right=NULL;
		cur->right=node;
		cur=cur->right;
	} 
}
