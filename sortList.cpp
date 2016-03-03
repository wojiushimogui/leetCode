#include<stdio.h>
#include<stdlib.h>
//Sort a linked list in O(n log n) time using constant space complexity.
struct ListNode {
     int val;
     struct ListNode *next;
};

/*
思路：利用快排的思想来做 
*/
struct ListNode* merge(struct ListNode* head,struct ListNode* newHead){
	if(head==NULL){
		return newHead;
	}
	if(newHead==NULL){
		return head;
	}
	//以两个链表中第一个元素相比较的较小值作为参考链表
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
		else if(cur2->val<cur1->val){//开始插入 
			next2=cur2->next;
			pre1->next=cur2;
			cur2->next=cur1;
			pre1=cur2;//注意：要更新pre1的指向 
			cur2=next2; 			
		}		
	}
	if(cur1==NULL&&cur2!=NULL){//newHead中的节点的值比较大，还有剩余 
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
