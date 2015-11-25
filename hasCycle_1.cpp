


/**
 * Definition for singly-linked list.
  struct ListNode {
      int val;
      struct ListNode *next;
  };
 */
/*
思路:用两个指针来进行遍历即可 ,一个只移动一个节点，一个移动两个节点 
*/
struct ListNode {
      int val;
      struct ListNode *next;
  };
bool hasCycle(struct ListNode *head) {
    if(head==NULL||head->next==NULL){//没有节点和只有一个节点不会出现环 
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
	//如果oneStep和twoStep指针指向了同一个节点，则必定有环
	return true; 
	
	
}
