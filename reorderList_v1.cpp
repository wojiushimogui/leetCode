


//合并两个链表 
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
	cur->next=pre;//把最后一个节点连接上 
	return cur;
}
/*
思路：先找到即将要插入的后面一半的链表的起始点，然后将其翻转，最后合并即为所有 
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
	//翻转slow后面的节点成为一个新的链表 
	struct ListNode* node=reverseList(slow->next);
	slow->next=NULL;
	//合并
	combineList(head,node);
}
