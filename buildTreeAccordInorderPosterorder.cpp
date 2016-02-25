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
	//�ں��������ȡ����ǰ��ͷ��㣬�����������һ��Ԫ�� 
	int curheadNodeValue=postorder[postorder_endIndex];
	//�ڶ�����������������ҳ���ǰͷ������ڵ�λ��
	int index_curheadNode=-1;
	for(int index_treeNode=inorder_startIndex;index_treeNode<=inorder_endIndex;index_treeNode++){//ע��Ⱥ� 
		if(curheadNodeValue==inorder[index_treeNode]){
			index_curheadNode=index_treeNode;
			break;
		}
	}
	if(index_curheadNode==-1){
		printf("��ǰ��������������û���ҵ�����ˣ����ܹ��ؽ��˶�����������");
	} 
	//�����˵�ǰ�����
	(*head)=(struct TreeNode *)malloc(sizeof(struct TreeNode));
	if((*head)==NULL){
		exit(EXIT_FAILURE);
	}
	(*head)->val=curheadNodeValue;
	(*head)->left=NULL;
	(*head)->right=NULL;
	/*
	��󣬹�����ǰ�������ӽ�㣬����ֵ��ע���һ���ǣ�����������������������ͺ��������ԭ�������е������յ�
	Ϊ����۲죬�������յ㵥����ϸ��д���������£� 
	*/
	int inorder_left_startIndex=inorder_startIndex;
	int inorder_left_endIndex= index_curheadNode-1;
	int inorder_right_startIndex=index_curheadNode+1;
	int inorder_right_endIndex=inorder_endIndex;
	
	int postorder_left_startIndex=postorder_startIndex;
	int postorder_left_endIndex=postorder_startIndex+(inorder_left_endIndex-inorder_left_startIndex);//��������������ͺ�������ĳ�����ȵ����� 
	int postorder_right_startIndex=postorder_left_endIndex+1;
	int postorder_right_endIndex=postorder_endIndex-1; 
	
	rebuildTree(&((*head)->left),inorder,inorder_left_startIndex,inorder_left_endIndex,postorder,postorder_left_startIndex,postorder_left_endIndex); 
	rebuildTree(&((*head)->right),inorder,inorder_right_startIndex,inorder_right_endIndex,postorder,postorder_right_startIndex,postorder_right_endIndex); 	
}
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    //��Ч�Լ��
	if(inorderSize!=postorderSize){
		return NULL;
	}
	struct TreeNode *head=NULL;//�����ͷָ��
	int inorder_startIndex=0;
	int inorder_endIndex=inorderSize-1;
	int postorder_startIndex=0;
	int postorder_endIndex=postorderSize-1; 
	rebuildTree(&head,inorder,inorder_startIndex,inorder_endIndex,postorder,postorder_startIndex,postorder_endIndex);
	return head;
}
