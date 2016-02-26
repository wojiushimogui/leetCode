#include<stdio.h>
#include<stdlib.h>

/**
 * Definition for a binary tree node.*/
  struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };
//˼·�����ϵ��¿�ʼ�������ж��Ƿ���ڸ߶Ȳ����1. ת��Ϊ��ÿ���ڵ�������� 
int max(int a,int b){
	return (a>=b)?a:b;
}
int nodeDepth(struct TreeNode* root){
	if(root==NULL){
		return 0;
	}
	//��ǰ�ڵ�����������ĸ߶� 
	int leftSubNodeDepth=nodeDepth(root->left);
	int rightSubNodeDepth=nodeDepth(root->right); 
	return max(leftSubNodeDepth,rightSubNodeDepth)+1; 
}
bool isBalancedHelper(struct TreeNode* root){
    if(root==NULL){
		return true;
	} 
	//���жϵ�ǰ�ڵ��Ƿ�Ϊ�߶�ƽ��� 
	int dif=nodeDepth(root->left)-nodeDepth(root->right);
    if(dif>1||dif<-1){//ע���Ǿ���ֵ����1 �ͷ���false 
    	return false;
	} 
	//�����жϵ�ǰ�ڵ�������ӽڵ��Ƿ��Ǹ߶�ƽ��� 
	return isBalancedHelper(root->left)&&isBalancedHelper(root->right);
}
bool isBalanced(struct TreeNode* root) {
	if(root==NULL){
		return true;
	} 
	return isBalancedHelper(root);
	
}
