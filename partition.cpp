


 struct ListNode {
      int val;
      struct ListNode *next;
  };
struct ListNode* partition(struct ListNode* head, int x) {
    if(head==NULL||head->next==NULL){//�޽ڵ��ֻ��һ���ڵ㣬������
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
	struct ListNode *lessThan=NULL;//����ָʾ���ұ�С��x�Ľڵ� 
	struct ListNode *LessThanNext=NULL; 
	struct ListNode *pre=NULL;
	while(cur!=NULL){
		if(cur->val<x){
			if(lessThan==NULL){
			    if(cur==head){
			        dummy->next=cur;//��ʱcurΪ��һ��С��x�Ľڵ�
			        lessThan=cur;
			        pre=cur;
			        cur=cur->next;
			        //continue;
			    }
			    else{
			        dummy->next=cur;//��ʱcurΪ��һ��С��x�Ľڵ�
    				lessThan=cur; 
    				curNext=cur->next;//����ǰ����һ���ڵ㱣�� 
    				cur->next=head;//ָ��ͷ���
    				pre->next=curNext;
    				cur=curNext;
			    }
				
			}
			else{
				if(lessThan==pre){//������С��x������Ҫ��������ı任ָ�� 
					lessThan=cur;
					pre=cur;
					cur=cur->next;
					continue;
				}
				LessThanNext=lessThan->next;//�Ȱ�lessThan����һ���ڵ㱣�� 
				lessThan->next=cur;
				curNext=cur->next;//����ǰ����һ���ڵ㱣�� 
				cur->next=LessThanNext;
				pre->next=curNext; 
				cur=curNext;//��ʱpre����Ҫ��
				lessThan=lessThan->next;//�ı�lessThan 
				 
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
	else{//�ڵ���ȫ������x
	    return head;
	}
}
