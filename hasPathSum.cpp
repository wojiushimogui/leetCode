#include<stdio.h>
#include<stdlib.h>
struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
  };
/*
˼·��˼·���жϸýڵ��Ƿ�ΪҶ�ӽڵ㣬�����Ҷ�ӽڵ㣬
���жϸýڵ��val�Ƿ���sum��ȣ��������Ҷ�ӽڵ㣬���жϸýڵ�������������Ƿ����·���ĺ͵��ڣ�sum-root->val��; 
*/ 
bool hasPathSum(struct TreeNode* root, int sum) {
    //��Ч�Լ��
	if(root==NULL){
		return false;
	} 
	if(root->left==NULL&&root->right==NULL){//����Ҷ�ӽڵ㣬�ж��Ƿ����sum 
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
