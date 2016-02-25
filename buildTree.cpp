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
	//找到当前头结点在中序遍历的位置
	int index_curHeadNode=-1;
	for(int index_node=0;index_node<len;index_node++){
		if(curHeadNodeValue==inorder[index_node]){
			index_curHeadNode=index_node;
			break;
		}
	}
	//
	if(index_curHeadNode==-1){
		printf("存在根节点在中序遍历中找不到，因此不能够构建二叉树！！"); 
	} 
	//开始构建当前头结点
	*head=(struct TreeNode*)malloc(sizeof(TreeNode));
	if((*head)==NULL){
		exit(EXIT_FAILURE);
	} 
	(*head)->val=curHeadNodeValue;
	(*head)->left=NULL;
	(*head)->right=NULL;
	//最后，在此头结点的基础上开始构建其左右节点,不过，值得注意的是：左节点、右节点在原来前序遍历和中序遍历中出现的位置 
	buildCurrentNode(&((*head)->left),index_curHeadNode,preorder+1,inorder);
	buildCurrentNode(&((*head)->right),len-(index_curHeadNode+1),preorder+index_curHeadNode+1,inorder+index_curHeadNode+1);
} 
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
	if(preorderSize!=inorderSize){
		return NULL;
	}
    struct TreeNode* head=NULL;//用来保存最后的树节点
    int len=preorderSize;
	buildCurrentNode(&head,len,preorder,inorder); 
    return head;
}
