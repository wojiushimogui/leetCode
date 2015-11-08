/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/*
˼·����дһ�����ڳ���Ϊk������ת��Ȼ�����õݹ齫�����
*/
/*
������˵����
@param head�������ͷ���
@param n:�����н��ĸ���
����ֵ�����������ͷ���
*/
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
      int val;
      struct ListNode *next;
  };
struct ListNode *reverseList(struct ListNode *head,int n){
    if(head==NULL||n<1){
        return NULL;
    }
    struct ListNode *print=head;
    while(print!=NULL){
		printf("��תǰ%d  ",print->val);
		print=print->next;
	} 
    struct ListNode *pre=NULL;
    struct ListNode *cur=head;
    struct ListNode *next=NULL;
    for(int i=0;i<n-1;i++){
        next=cur->next;//������һ�����ָ��
        cur->next=pre;
        pre=cur;
        cur=next;//
    }
    //forѭ������ʱ��curָ��ԭ��������һ����㡣���������ͷ���
    cur->next=pre;
    
    struct ListNode *printNode=cur;
	while(printNode!=NULL){
		printf("��ת��%d  ",printNode->val);
		printNode=printNode->next;
	} 
    
    return cur;
    
}
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if(head==NULL||k<0){
        return NULL;
    }
    //��������ĳ���
    struct ListNode *temp=head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    if(k>len){//��k����������ʱ������ԭ����ͷ���
        return head;
    }
    if(k==1){//����ת��ֱ�ӷ��� 
    	return head;
	}
    //��ʼ��k�����Ϊһ�������з�ת
    struct ListNode *cur=head;
    struct ListNode *pre=NULL; 
    struct ListNode *curHead=head;
    struct ListNode *nextHead=NULL;
    struct ListNode **allHead=(struct ListNode **)malloc((len/k)*sizeof(struct ListNode *));
    if(allHead==NULL){
        exit(EXIT_FAILURE);
    }
    int index=0;
    int count=len/k;
    for(int i=0;i<count;i++){
        //��k�����Ϊ�Σ�������һ������Ҫ��ת��ͷ���
        for(int i=0;i<k;i++){
        	pre=cur;
            cur=cur->next;//��һ�ֵ�ͷ���
        }
        //�Ƚ�ͷһ�η�ת
        pre->next=NULL;
        
        allHead[index]=reverseList(curHead,k);
        index++;
        //���������Ϊʲôû�б��أ����� 
        curHead=cur;
    }//��forѭ��������ʱ��curHeadָ�����û�з�ת��ʣ�����ͷ���
    
    //�������������ƴ��������ok��
    struct ListNode *newListHead=allHead[0];
    struct ListNode *node=allHead[0];
    for(int i=0;i<index;i++){
        for(int j=0;j<k-1;j++){//ʹnodeָ�����һ�����
            node=node->next;
        }
        if(i!=index-1){
            node->next=allHead[i+1];
            node=node->next;//ʹ�Ľ��ָ���һ�ε�ͷ��� 
        }
        else{
            node->next=curHead;
        }
        
    }
    return newListHead;
      
}
int main(void){
	//����һ������
	ListNode *node1=(ListNode *)malloc(sizeof(ListNode)); 
	ListNode *node2=(ListNode *)malloc(sizeof(ListNode)); 
	ListNode *node3=(ListNode *)malloc(sizeof(ListNode)); 
	ListNode *node4=(ListNode *)malloc(sizeof(ListNode)); 
	ListNode *node5=(ListNode *)malloc(sizeof(ListNode)); 
	node1->val=8;
	node1->next=node2;
	node2->val=7;
	node2->next=node3;
	node3->next=node4;
	node3->val=3;
	node4->next=node5;
	node4->val=5;
	node5->next=NULL;
	node5->val=18;
	ListNode *head=reverseKGroup(node1,2);
	printf("\n");
	while(head!=NULL){
		printf("%d   ",head->val);
		head=head->next;
	}
	
//	ListNode *head=(ListNode *)malloc(sizeof(ListNode)); 
				
	return 0;
}
