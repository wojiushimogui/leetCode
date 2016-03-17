
struct ListNode {
      int val;
      struct ListNode *next;
  };
struct ListNode* reverseList(struct ListNode* head) {
    if(head==NULL){
    	return NULL;
	}
	struct ListNode* cur=head;
	struct ListNode* pre=NULL;
	struct ListNode* next=NULL;
	while(cur!=NULL){
		next=cur->next;
		cur->next=pre;
		pre=cur;
		cur=next;
	}
	return pre;
}
