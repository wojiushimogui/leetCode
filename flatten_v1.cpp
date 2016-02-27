#include<stdio.h>
#include<stdlib.h> 

struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
};
/*
˼·��������˶�������ǰ�������Ȼ����й��� 
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
    //��һ���������������ǰ�����
    int treeNodePreOrder[N];   
    int index=0;
	getPreOrder(root,treeNodePreOrder,&index); 
	//�ڶ��������й���
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
