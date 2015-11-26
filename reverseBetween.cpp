#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
 * Definition for singly-linked list.
  struct ListNode {
      int val;
      struct ListNode *next;
  };
 */

struct ListNode {
      int val;
      struct ListNode *next;
  };
 struct ListNode* reverse(struct ListNode* head){
	if(head==NULL){
		return NULL;
	}
	struct ListNode *pre=NULL;
	struct ListNode *cur=head;
	struct ListNode *next=NULL;
	while(cur){
		next=cur->next;
		cur->next=pre;
		pre=cur;
		cur=next;
	}
	return pre;
	
}
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    if(head==NULL||m<0||n<0||m>n){//��Ч�Լ�� 
    	return NULL;
	} 
	if(m==n){
		return head;
	}
	//��������ĳ��ȣ��ж�m��n��ȡֵ�Ƿ��ڳ��ȷ�Χ֮�� 
	struct ListNode *cur1=head;
	int len=0;
	while(cur1){
		len++;
		cur1=cur1->next;
	}
	if(m>len||n>len){//m��n�ĳ��Ȳ��ܴ��������нڵ�ĸ��� 
		return NULL;
	}
	cur1=head;//cur�ڵ�����ָ��ͷ��� 
	int mm=m;//������m��ֵ 
	struct ListNode *pre=NULL;
	while(m>1){//�ҵ�Ҫ��ת��ǰһ���ڵ�pre�͵�һ�����cur1 
		pre=cur1; 
		cur1=cur1->next; 
		m--;		
	} 
	struct ListNode *cur2=cur1;
	while(cur2!=NULL&&n>mm){//ʹ��cur2ָ��תָ��ĵ�һ����� 
		cur2=cur2->next;
		n--;
	}
	struct ListNode *next=cur2->next; //Ҫ��ת������һ���ڵ����һ���ڵ� ��Ϊ������������׼�� 
	//��ʼ��ת,�ȶϿ�m~n�ڵ���Ϊ����Ҫ��ת������ 
	//���ж���pre�Ƿ�Ϊ�գ�����m=1ʱΪ��;�����Ϊ�գ��������� 
	if(pre){
		pre->next=NULL;
		
	} 
	cur2->next=NULL; 
	
	//��ʼ��ת
	struct ListNode *newHead=reverse(cur1);
	//��������
	//���ж���pre�Ƿ�Ϊ�գ���Ϊ�գ���newHead���ǵ�һ����� 
	if(pre){
		pre->next=newHead;
		
	}
	else{
	    //��Ϊ�գ���newHeadΪͷ���
	    head=newHead; 
	}
//	pre=newHead;

	//����next����Ľڵ��������� 
	while(newHead!=NULL){
		pre=newHead;
		newHead=newHead->next;
	} 
	
	 pre->next=next;
	 
	
	return head;	 
}
#define N  3
int main(void){
	struct ListNode *head=(struct ListNode *)malloc(sizeof(ListNode ));
	if(head==NULL){
		exit(EXIT_FAILURE);
	}
	head->val=4;
	struct ListNode *node1=(struct ListNode *)malloc(sizeof(ListNode ));
	node1->val=9;
	head->next=node1;
	struct ListNode *node2=(struct ListNode *)malloc(sizeof(ListNode ));
	node2->val=2;
	node1->next=node2;
	node2->next=NULL;
	ListNode *result=reverseBetween( head, 2, 3);
	while(result){
	 	printf("%d  ",  result->val);
	 	result=result->next;
	 }
	
	return 0;
} 
