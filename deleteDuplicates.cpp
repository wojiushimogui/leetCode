


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/*
˼·������һ����������ͬ�Ľڵ����������ͺ� 
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 struct ListNode {
      int val;
      struct ListNode *next;
  };
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head==NULL){//��Ч�Լ�� 
    	return NULL;
	} 
	struct ListNode* cur=head;
	int val=head->val; 
	struct ListNode* pre=head;//������¼��ǰ����ֵ 
	struct ListNode* next=NULL;
	while(cur->next!=NULL){
		next=cur->next;
		if(val!=next->val){//����һ�γ��ֵĽڵ�next���뵽����� 
			pre->next=next;//���½ڵ� 
			val=next->val;
		}
		cur=next; 
	}
	pre->next=NULL;
	return head;	
}
