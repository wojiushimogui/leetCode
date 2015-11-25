


/**
 * Definition for singly-linked list.
  struct ListNode {
      int val;
      struct ListNode *next;
  };
 */
/*
思路:通过 
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
		if(cur->val!=-1000000000){//设置一个标志位 
			cur->val=-1000000000;
		}
		else{
			return true;
		}
		cur=cur->next; 
	}
	return false;
}
