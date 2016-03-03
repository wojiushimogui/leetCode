


//�ϲ��������� 
void combineList(struct ListNode* head,struct ListNode* newHead){
	if(head==NULL){
		head=newHead;
		return ;
	} 
	if(newHead==NULL){
		return;
	}
	struct ListNode* cur1=head;
	struct ListNode* next1=NULL;
	struct ListNode* cur2=newHead;
	struct ListNode* next2=NULL;
	while(cur1!=NULL&&cur2!=NULL){
		next1=cur1->next;
		next2=cur2->next;
		cur1->next=cur2;
		if(next1!=NULL){
			cur2->next=next1;
		}		
		cur1=next1;
		cur2=next2;
	}	
} 
struct ListNode* reverseList(struct ListNode* head){
	if(head==NULL){
		return NULL;
	}
	struct ListNode* pre=NULL;
	struct ListNode* cur=head;
	struct ListNode* next=NULL;
	while(cur->next!=NULL){
		next=cur->next;
		cur->next=pre;
		pre=cur;
		cur=next;
	}
	cur->next=pre;//�����һ���ڵ������� 
	return cur;
}
/*
˼·�����ҵ�����Ҫ����ĺ���һ����������ʼ�㣬Ȼ���䷭ת�����ϲ���Ϊ���� 
*/
void reorderList(struct ListNode* head) {
    if(head==NULL||head->next==NULL){
    	return;
	}
	struct ListNode* slow=head;
	struct ListNode* fast=head;
	while(fast!=NULL&&fast->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
	} 
	//��תslow����Ľڵ��Ϊһ���µ����� 
	struct ListNode* node=reverseList(slow->next);
	slow->next=NULL;
	//�ϲ�
	combineList(head,node);
}
