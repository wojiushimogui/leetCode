
struct ListNode {
     int val;
     struct ListNode *next;
};
//利用两个for循环量解决这个问题 
struct ListNode* insertionSortList(struct ListNode* head) {
     if(head==NULL||head->next==NULL){
     	return head;
	 } 
	 //先找到此链表中最小的节点，即作为返回节点
	 int minVale=head->val;
	 struct ListNode* cur=head->next;
	 struct ListNode* returnHead=NULL;	 
	 while(cur!=NULL){
	 	if(cur->val<minValue){
	 		min=cur->val;
	 		returnHead=cur;
		 }
	 } 
	 cur=head->next;
	 struct ListNode* next=NULL;
	 struct ListNode* pre1=head;
	 while(cur!=NULL){
	 	next=cur->next;
	 	//在cur节点之前，找到他要插入的位置 
	 	struct ListNode* node=head;
	 	struct ListNode* pre=NULL;
	 	while(node!=cur){
	 		if(node->val<=cur->val){
	 			pre=node;
	 			node=node->next;
			 }
			 else if(cur->val<node->val){//开始插入 
			 	if(pre==NULL){//
			 		
				 }
			 	pre->next=cur;
			 	cur->next=node;
				break; 
			 }
		 }
		 if(node==cur){//此种情况为：即将要插入的节点大于前面所有的节点 
		 	cur=cur->next;
		 }
		 else{
		 	cur=next;
		 } 
	 }
}
