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
#define N  100000
void getPreOrder(struct TreeNode* root,struct TreeNode **treeNodePreOrder,int* index){
	if(root==NULL){
		return;
	}
	treeNodePreOrder[(*index)]=root;
	(*index)++;
	getPreOrder(root->left,treeNodePreOrder,index);
	getPreOrder(root->right,treeNodePreOrder,index);	
}
void flatten(struct TreeNode* root) {
    //第一步：求出二叉树的前序遍历
    struct TreeNode** treeNodePreOrder=(TreeNode** )malloc(N*sizeof(struct TreeNode *));
    if(treeNodePreOrder==NULL){
    	exit(EXIT_FAILURE);
	}   
    int index=0;
    
	getPreOrder(root,treeNodePreOrder,&index); 
	//第二步：进行构建
	struct TreeNode* cur=root;
	
	for(int i=1;i<index;i++){
		cur->right=treeNodePreOrder[i];
		cur->left=NULL;
		cur=cur->right;
	} 
}
