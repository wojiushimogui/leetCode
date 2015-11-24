


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/*
思路：遍历一次链表，将不同的节点连接起来就好 
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 struct ListNode {
      int val;
      struct ListNode *next;
  };
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head==NULL){//有效性检查 
    	return NULL;
	} 
	struct ListNode* cur=head;
	int val=head->val; 
	struct ListNode* pre=head;//用来记录当前结点的值 
	struct ListNode* next=NULL;
	while(cur->next!=NULL){
		next=cur->next;
		if(val!=next->val){//将第一次出现的节点next加入到结果中 
			pre->next=next;//更新节点 
			val=next->val;
		}
		cur=next; 
	}
	pre->next=NULL;
	return head;	
}
