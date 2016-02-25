#include<stdio.h>
#include<stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
void rebuildTree(struct TreeNode **head,int *inorder,int inorder_startIndex,int inorder_endIndex,int *postorder,int postorder_startIndex,int postorder_endIndex){
	if((inorder_endIndex<inorder_startIndex)||(postorder_endIndex<postorder_startIndex)){
		return;
	}
	if(inorder==NULL||postorder==NULL){
		return;
	}
	//在后序遍历中取出当前的头结点，即数组中最后一个元素 
	int curheadNodeValue=postorder[postorder_endIndex];
	//第二步：在中序遍历中找出当前头结点所在的位置
	int index_curheadNode=-1;
	for(int index_treeNode=inorder_startIndex;index_treeNode<=inorder_endIndex;index_treeNode++){//注意等号 
		if(curheadNodeValue==inorder[index_treeNode]){
			index_curheadNode=index_treeNode;
			break;
		}
	}
	if(index_curheadNode==-1){
		printf("当前结点在中序遍历中没有找到，因此，不能够重建此二叉树！！！");
	} 
	//构建此当前父结点
	(*head)=(struct TreeNode *)malloc(sizeof(struct TreeNode));
	if((*head)==NULL){
		exit(EXIT_FAILURE);
	}
	(*head)->val=curheadNodeValue;
	(*head)->left=NULL;
	(*head)->right=NULL;
	/*
	最后，构建当前的左右子结点，不过值得注意的一点是：构建左右子树的中序遍历和后序遍历在原来数组中的起点和终点
	为方便观察，则将起点和终点单独详细的写出来，如下： 
	*/
	int inorder_left_startIndex=inorder_startIndex;
	int inorder_left_endIndex= index_curheadNode-1;
	int inorder_right_startIndex=index_curheadNode+1;
	int inorder_right_endIndex=inorder_endIndex;
	
	int postorder_left_startIndex=postorder_startIndex;
	int postorder_left_endIndex=postorder_startIndex+(inorder_left_endIndex-inorder_left_startIndex);//利用了中序遍历和后序遍历的长度相等的特性 
	int postorder_right_startIndex=postorder_left_endIndex+1;
	int postorder_right_endIndex=postorder_endIndex-1; 
	
	rebuildTree(&((*head)->left),inorder,inorder_left_startIndex,inorder_left_endIndex,postorder,postorder_left_startIndex,postorder_left_endIndex); 
	rebuildTree(&((*head)->right),inorder,inorder_right_startIndex,inorder_right_endIndex,postorder,postorder_right_startIndex,postorder_right_endIndex); 	
}
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    //有效性检查
	if(inorderSize!=postorderSize){
		return NULL;
	}
	struct TreeNode *head=NULL;//结果的头指针
	int inorder_startIndex=0;
	int inorder_endIndex=inorderSize-1;
	int postorder_startIndex=0;
	int postorder_endIndex=postorderSize-1; 
	rebuildTree(&head,inorder,inorder_startIndex,inorder_endIndex,postorder,postorder_startIndex,postorder_endIndex);
	return head;
}
