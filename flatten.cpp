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
    //��һ���������������ǰ�����
    struct TreeNode** treeNodePreOrder=(TreeNode** )malloc(N*sizeof(struct TreeNode *));
    if(treeNodePreOrder==NULL){
    	exit(EXIT_FAILURE);
	}   
    int index=0;
    
	getPreOrder(root,treeNodePreOrder,&index); 
	//�ڶ��������й���
	struct TreeNode* cur=root;
	
	for(int i=1;i<index;i++){
		cur->right=treeNodePreOrder[i];
		cur->left=NULL;
		cur=cur->right;
	} 
}
