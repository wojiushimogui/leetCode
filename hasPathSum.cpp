#include<stdio.h>
#include<stdlib.h>
struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };
/*
思路：思路：判断该节点是否为叶子节点，如果是叶子节点，
则判断该节点的val是否与sum相等，如果不是叶子节点，则判断该节点的左右子树中是否存在路径的和等于（sum-root->val）; 
*/ 
bool hasPathSum(struct TreeNode* root, int sum) {
    //有效性检查
	if(root==NULL){
		return false;
	} 
	if(root->left==NULL&&root->right==NULL){//到达叶子节点，判断是否等于sum 
		if(root->val==sum){
			return true;
		} 
		else{
			return false;
		}
	}
	else{
		return hasPathSum(root->left,sum-root->val)||hasPathSum(root->right,sum-root->val);   
	}
}
