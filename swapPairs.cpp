/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. 
You may not modify the values in the list, only nodes itself can be changed.
*/

#include<stdio.h>
#include<stdlib.h>

/**
 * Definition for singly-linked list.*/
 /*
 ˼·�������пռ�����ƣ���ˣ����ǲ��ܹ������������ڵ�Ϊһ�飬Ȼ���䷭ת��Ȼ�󴢴��µ�ͷ��㣬���������������
 
 ��Ҫ��������˼·�� 
 */
  struct ListNode {
      int val;
      struct ListNode *next;
  };
 
struct ListNode* swapPairs(struct ListNode* head) {
    if(head==NULL){
    	return NULL;
	}
	if(head->next==NULL){//ֻ��һ���ڵ����� 
		return head;
	} 
	struct ListNode *cur=head;
	struct ListNode *nextNode=cur->next;
	head=nextNode;//�����µ�ͷ��㡣 
	struct ListNode *nextNextNode=cur->next->next;
	while(nextNode!=NULL){
		if(nextNextNode!=NULL&&nextNextNode->next!=NULL){
			nextNode->next=cur;
			cur->next=nextNextNode->next;
			cur=nextNextNode;
			nextNode=nextNextNode->next;
			nextNextNode=nextNextNode->next->next; 
		}
		else{//ֻʣ����������ڵ�
			//��cur��cur->next�����Ϳ�����
			nextNode->next=cur;
			cur->next=nextNextNode;//�������������㣬�����һ��nextNextNodeΪ���һ���ڵ㣬Ϊż�����㣬�����һ��nextNextNodeΪNULL�� 
			break; //��ʱ���ں���û�нڵ��ˣ�����˳��Ϳ����ˡ� 
			
		}
			
	}
	return head; 
} 


int main(void){
	
	return 0;
}
