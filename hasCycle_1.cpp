


/**
 * Definition for singly-linked list.
  struct ListNode {
      int val;
      struct ListNode *next;
  };
 */
/*
˼·:������ָ�������б������� ,һ��ֻ�ƶ�һ���ڵ㣬һ���ƶ������ڵ� 
*/
struct ListNode {
      int val;
      struct ListNode *next;
  };
bool hasCycle(struct ListNode *head) {
    if(head==NULL||head->next==NULL){//û�нڵ��ֻ��һ���ڵ㲻����ֻ� 
    	return false;
	}
	struct ListNode *oneStep=head;
	struct ListNode *twoStep=head->next; 
	while(oneStep!=twoStep){
		if(twoStep==NULL||oneStep==NULL||twoStep->next==NULL) return false;
		else{
			oneStep=oneStep->next;
			twoStep=twoStep->next->next;
		}
	}
	//���oneStep��twoStepָ��ָ����ͬһ���ڵ㣬��ض��л�
	return true; 
	
	
}
