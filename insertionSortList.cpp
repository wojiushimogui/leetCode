
struct ListNode {
     int val;
     struct ListNode *next;
};
//��������forѭ�������������� 
struct ListNode* insertionSortList(struct ListNode* head) {
     if(head==NULL||head->next==NULL){
     	return head;
	 } 
	 //���ҵ�����������С�Ľڵ㣬����Ϊ���ؽڵ�
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
	 	//��cur�ڵ�֮ǰ���ҵ���Ҫ�����λ�� 
	 	struct ListNode* node=head;
	 	struct ListNode* pre=NULL;
	 	while(node!=cur){
	 		if(node->val<=cur->val){
	 			pre=node;
	 			node=node->next;
			 }
			 else if(cur->val<node->val){//��ʼ���� 
			 	if(pre==NULL){//
			 		
				 }
			 	pre->next=cur;
			 	cur->next=node;
				break; 
			 }
		 }
		 if(node==cur){//�������Ϊ������Ҫ����Ľڵ����ǰ�����еĽڵ� 
		 	cur=cur->next;
		 }
		 else{
		 	cur=next;
		 } 
	 }
}
