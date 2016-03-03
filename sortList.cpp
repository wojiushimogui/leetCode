#include<stdio.h>
#include<stdlib.h>
//Sort a linked list in O(n log n) time using constant space complexity.
struct ListNode {
     int val;
     struct ListNode *next;
};

/*
˼·�����ÿ��ŵ�˼������ 
*/
struct ListNode* merge(struct ListNode* head,struct ListNode* newHead){
	if(head==NULL){
		return newHead;
	}
	if(newHead==NULL){
		return head;
	}
	//�����������е�һ��Ԫ����ȽϵĽ�Сֵ��Ϊ�ο�����
	struct ListNode* cur1=NULL;
	struct ListNode* pre1=NULL;
	struct ListNode* cur2=NULL;
	struct ListNode* next2=NULL;
	
	struct ListNode* returnHead=NULL;
	if(head->val<=newHead->val){
		returnHead=head;
		cur1=head;
		cur2=newHead;
	} 
	else{
		returnHead=newHead;
		cur1=newHead;
		cur2=head;
	}
	 
	while(cur1!=NULL&&cur2!=NULL){
		if(cur1->val<=cur2->val){
			pre1=cur1;
			cur1=cur1->next;			
		}
		else if(cur2->val<cur1->val){//��ʼ���� 
			next2=cur2->next;
			pre1->next=cur2;
			cur2->next=cur1;
			pre1=cur2;//ע�⣺Ҫ����pre1��ָ�� 
			cur2=next2; 			
		}		
	}
	if(cur1==NULL&&cur2!=NULL){//newHead�еĽڵ��ֵ�Ƚϴ󣬻���ʣ�� 
		pre1->next=cur2;
	}
	return returnHead;	
}
struct ListNode* sortList(struct ListNode* head) {
    if(head==NULL||head->next==NULL){
    	return head;
	} 
	struct ListNode* midNode=head;
	struct ListNode* fast=head->next;
	while(fast!=NULL&&fast->next!=NULL){
		midNode=midNode->next;
		fast=fast->next->next;
	}
	struct ListNode* newHead=midNode->next;
	midNode->next=NULL;
	struct ListNode* h1=sortList(head);
	struct ListNode* h2=sortList(newHead);
	return merge(h1,h2);
}
