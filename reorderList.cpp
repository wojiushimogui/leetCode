

/**
 * Definition for singly-linked list.*/
  struct ListNode {
      int val;
      struct ListNode *next;
  };
 //在leetcode中报超时错误，不能AC 
void reorderList(struct ListNode* head) {
    if(head==NULL||head->next==NULL){
    	return;
	}
	//用两个for循环来做：时间复杂度为O(n*n) 
	struct ListNode* cur=head;
	struct ListNode* next=NULL;
	struct ListNode* final=NULL;
	struct ListNode* preFinal=NULL;
	while(cur->next!=NULL&&cur->next->next!=NULL){
		next=cur->next;//保存下一个节点 
		//使得node指向最后一个节点的位置 
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
