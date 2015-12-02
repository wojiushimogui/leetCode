


 struct ListNode {
      int val;
      struct ListNode *next;
  };
struct ListNode* partition(struct ListNode* head, int x) {
    if(head==NULL||head->next==NULL){//无节点和只有一个节点，都返回
    	return head;
	}
	struct ListNode *dummy=(struct ListNode *)malloc(sizeof(struct ListNode));
	if(dummy==NULL){
		exit(EXIT_FAILURE);
	}
	dummy->next=NULL;
	struct ListNode *index=dummy;
	struct ListNode *cur=head;
	struct ListNode *curNext=NULL;
	struct ListNode *lessThan=NULL;//用来指示最右边小于x的节点 
	struct ListNode *LessThanNext=NULL; 
	struct ListNode *pre=NULL;
	while(cur!=NULL){
		if(cur->val<x){
			if(lessThan==NULL){
			    if(cur==head){
			        dummy->next=cur;//此时cur为第一个小于x的节点
			        lessThan=cur;
			        pre=cur;
			        cur=cur->next;
			        //continue;
			    }
			    else{
			        dummy->next=cur;//此时cur为第一个小于x的节点
    				lessThan=cur; 
    				curNext=cur->next;//将当前的下一个节点保存 
    				cur->next=head;//指向头结点
    				pre->next=curNext;
    				cur=curNext;
			    }
				
			}
			else{
				if(lessThan==pre){//即都是小于x，不需要进行下面的变换指针 
					lessThan=cur;
					pre=cur;
					cur=cur->next;
					continue;
				}
				LessThanNext=lessThan->next;//先把lessThan的下一个节点保存 
				lessThan->next=cur;
				curNext=cur->next;//将当前的下一个节点保存 
				cur->next=LessThanNext;
				pre->next=curNext; 
				cur=curNext;//此时pre不需要变
				lessThan=lessThan->next;//改变lessThan 
				 
			}
		}
		else{
			pre=cur;
			cur=cur->next;
		} 
		
	}
	if(dummy->next!=NULL){
	    return dummy->next;
	   
	}
	else{//节点中全部大于x
	    return head;
	}
}
