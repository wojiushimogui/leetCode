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
 思路：由于有空间的限制，因此，我们不能够将其以两个节点为一组，然后将其翻转，然后储存新的头结点，最后将其连接起来。
 
 需要我们想别的思路： 
 */
  struct ListNode {
      int val;
      struct ListNode *next;
  };
 
struct ListNode* swapPairs(struct ListNode* head) {
    if(head==NULL){
    	return NULL;
	}
	if(head->next==NULL){//只有一个节点的情况 
		return head;
	} 
	struct ListNode *cur=head;
	struct ListNode *nextNode=cur->next;
	head=nextNode;//保存新的头结点。 
	struct ListNode *nextNextNode=cur->next->next;
	while(nextNode!=NULL){
		if(nextNextNode!=NULL&&nextNextNode->next!=NULL){
			nextNode->next=cur;
			cur->next=nextNextNode->next;
			cur=nextNextNode;
			nextNode=nextNextNode->next;
			nextNextNode=nextNextNode->next->next; 
		}
		else{//只剩下最后两个节点
			//将cur和cur->next交换就可以了
			nextNode->next=cur;
			cur->next=nextNextNode;//如果是奇数个结点，则最后一个nextNextNode为最后一个节点，为偶数个点，则最后一个nextNextNode为NULL； 
			break; //此时由于后面没有节点了，因此退出就可以了。 
			
		}
			
	}
	return head; 
} 


int main(void){
	
	return 0;
}
