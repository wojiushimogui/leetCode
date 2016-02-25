#include<stdio.h>
#include<stdlib.h>

/**http://blog.csdn.net/u010412719/article/details/49227411
  Definition for a binary tree node.*/
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
void buildCurrentNode(struct TreeNode **head,int len,int *preorder,int *inorder){
	if(len<=0){
		return;
	}
	if(preorder==NULL||inorder==NULL){
		return ;
	}
	//
	int curHeadNodeValue= preorder[0];
	//�ҵ���ǰͷ��������������λ��
	int index_curHeadNode=-1;
	for(int index_node=0;index_node<len;index_node++){
		if(curHeadNodeValue==inorder[index_node]){
			index_curHeadNode=index_node;
			break;
		}
	}
	//
	if(index_curHeadNode==-1){
		printf("���ڸ��ڵ�������������Ҳ�������˲��ܹ���������������"); 
	} 
	//��ʼ������ǰͷ���
	*head=(struct TreeNode*)malloc(sizeof(TreeNode));
	if((*head)==NULL){
		exit(EXIT_FAILURE);
	} 
	(*head)->val=curHeadNodeValue;
	(*head)->left=NULL;
	(*head)->right=NULL;
	//����ڴ�ͷ���Ļ����Ͽ�ʼ���������ҽڵ�,������ֵ��ע����ǣ���ڵ㡢�ҽڵ���ԭ��ǰ���������������г��ֵ�λ�� 
	buildCurrentNode(&((*head)->left),index_curHeadNode,preorder+1,inorder);
	buildCurrentNode(&((*head)->right),len-(index_curHeadNode+1),preorder+index_curHeadNode+1,inorder+index_curHeadNode+1);
} 
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
	if(preorderSize!=inorderSize){
		return NULL;
	}
    struct TreeNode* head=NULL;//���������������ڵ�
    int len=preorderSize;
	buildCurrentNode(&head,len,preorder,inorder); 
    return head;
}
