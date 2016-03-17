#include<stdio.h>
#include<stdlib.h>

struct ListNode {
      int val;
      struct ListNode *next;
  };
struct ListNode* removeElements(struct ListNode* head, int val) {
    if(head==NULL){
    	return NULL;
	} 
	struct ListNode* cur=head;
	struct ListNode* pre=NULL;
	struct ListNode* next=NULL;
	while(cur!=NULL){
		next=cur->next;
		if(cur->val==val){
			cur->next=NULL;
			if(pre!=NULL){
				pre->next=next;
			}
			else{
				head=next;
			}			
			cur=next;
		}
		else{
			pre=cur;
			cur=next;
		}
	}
	return head;
}
