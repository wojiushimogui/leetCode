


/**
 * Definition for singly-linked list.
  struct ListNode {
      int val;
      struct ListNode *next;
  };
 */
/*
˼·:ͨ�� 
*/
struct ListNode {
      int val;
      struct ListNode *next;
  };
bool hasCycle(struct ListNode *head) {
    if(head==NULL){
    	return false;
	}
	struct ListNode *cur=head;
	struct ListNode *next=head;
	while(cur->next!=NULL){
		if(cur->val!=-1000000000){//����һ����־λ 
			cur->val=-1000000000;
		}
		else{
			return true;
		}
		cur=cur->next; 
	}
	return false;
}
