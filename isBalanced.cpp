#include<stdio.h>
#include<stdlib.h>

/**
 * Definition for a binary tree node.*/
  struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };
//思路：从上到下开始遍历，判断是否存在高度差大于1. 转化为求每个节点的最大深度 
int max(int a,int b){
	return (a>=b)?a:b;
}
int nodeDepth(struct TreeNode* root){
	if(root==NULL){
		return 0;
	}
	//当前节点的左右子树的高度 
	int leftSubNodeDepth=nodeDepth(root->left);
	int rightSubNodeDepth=nodeDepth(root->right); 
	return max(leftSubNodeDepth,rightSubNodeDepth)+1; 
}
bool isBalancedHelper(struct TreeNode* root){
    if(root==NULL){
		return true;
	} 
	//先判断当前节点是否为高度平衡的 
	int dif=nodeDepth(root->left)-nodeDepth(root->right);
    if(dif>1||dif<-1){//注意是绝对值大于1 就返回false 
    	return false;
	} 
	//继续判断当前节点的左右子节点是否是高度平衡的 
	return isBalancedHelper(root->left)&&isBalancedHelper(root->right);
}
bool isBalanced(struct TreeNode* root) {
	if(root==NULL){
		return true;
	} 
	return isBalancedHelper(root);
	
}
