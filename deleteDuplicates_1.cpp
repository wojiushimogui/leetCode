

/*
思路：遍历一次链表，将只有一次的节点连接起来就好 
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
	struct ListNode* pre=NULL;//用来记录当前结点的值 
	struct ListNode* next=NULL;
	int count=1;
	while(cur->next!=NULL){
		next=cur->next;
		if(cur->val==next->val){
			count++;
		} 
		else if(cur->val!=next->val){
			if(count<2){//即cur指针所指向的节点就是只出现了一次的节点 
				if(pre!=NULL){//说明 
					pre->next=cur;
					pre=cur;
				}
				else{//此时pre为NULL，说明cur所指向的节点为第一个出现一次的节点 
					pre=cur;
					head=pre;
				}
				count=1; 
			}
			else{//仅仅将count=1即可 
				count=1;
			}
		}
		cur=next; 
	}
	if(count==1&&pre==NULL){//只有1个节点的情况或者是出现类似1 1 2这种情况
		return cur;
	}
	else if(count>1&&pre==NULL){//有多个相同的节点的情况
		return NULL;
	}
	else if(count==1&&pre!=NULL){//判定最后一个节点是不是只出现了一次 
	    pre->next=cur;
	}
	else if(count>1&&pre!=NULL){
	    pre->next=NULL;
	}
	return head;	
}
