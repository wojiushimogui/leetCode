#include<stdio.h>
#include<stdlib.h>

/**
 * Definition for singly-linked list.*/
  struct ListNode {
      int val;
      struct ListNode *next;
  };
int getListLen(struct ListNode *head){
	if(head==NULL){
		return 0;
	}
	struct ListNode *cur=head;
	int len=0;
	while(cur!=NULL){
		len++;
		cur=cur->next;
	}
	return len;
} 
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(headA==NULL||headB==NULL){
    	return NULL;
	}
	//���������A��B�ĳ��Ȳ�
	int listALen=getListLen(headA);
	int listBLen=getListLen(headB); 
	struct ListNode *curLargeList=NULL;
	struct ListNode *curLowList=NULL;
	int dif=0;
	if(listALen>=listBLen){//ע�⣺�Ⱥ������д���������ifҪд 
		dif=listALen-listBLen;
		curLargeList=headA;
		curLowList=headB;
	}
	if(listALen<listBLen){
		dif=listBLen-listALen;
		curLargeList=headB;
		curLowList=headA;
	}
	while(dif>0){
		curLargeList=curLargeList->next;
		dif--;
	}
	while(curLargeList!=curLowList){
		curLargeList=curLargeList->next;
		curLowList=curLowList->next;
	}
	return curLargeList;
}
