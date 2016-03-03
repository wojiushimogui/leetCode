

/**
 * Definition for singly-linked list.*/
  struct ListNode {
      int val;
      struct ListNode *next;
  };
 //��leetcode�б���ʱ���󣬲���AC 
void reorderList(struct ListNode* head) {
    if(head==NULL||head->next==NULL){
    	return;
	}
	//������forѭ��������ʱ�临�Ӷ�ΪO(n*n) 
	struct ListNode* cur=head;
	struct ListNode* next=NULL;
	struct ListNode* final=NULL;
	struct ListNode* preFinal=NULL;
	while(cur->next!=NULL&&cur->next->next!=NULL){
		next=cur->next;//������һ���ڵ� 
		//ʹ��nodeָ�����һ���ڵ��λ�� 
		final=cur;
		preFinal=NULL;
		while(final->next!=NULL){
			preFinal=final;
			final=final->next;
		}
		preFinal->next=NULL;
		cur->next=final;
		final->next=next;
		cur=next; 
	} 
}
