

/*
˼·������һ��������ֻ��һ�εĽڵ����������ͺ� 
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 struct ListNode {
      int val;
      struct ListNode *next;
  };
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head==NULL){//��Ч�Լ�� 
    	return NULL;
	} 
	struct ListNode* cur=head;
	struct ListNode* pre=NULL;//������¼��ǰ����ֵ 
	struct ListNode* next=NULL;
	int count=1;
	while(cur->next!=NULL){
		next=cur->next;
		if(cur->val==next->val){
			count++;
		} 
		else if(cur->val!=next->val){
			if(count<2){//��curָ����ָ��Ľڵ����ֻ������һ�εĽڵ� 
				if(pre!=NULL){//˵�� 
					pre->next=cur;
					pre=cur;
				}
				else{//��ʱpreΪNULL��˵��cur��ָ��Ľڵ�Ϊ��һ������һ�εĽڵ� 
					pre=cur;
					head=pre;
				}
				count=1; 
			}
			else{//������count=1���� 
				count=1;
			}
		}
		cur=next; 
	}
	if(count==1&&pre==NULL){//ֻ��1���ڵ����������ǳ�������1 1 2�������
		return cur;
	}
	else if(count>1&&pre==NULL){//�ж����ͬ�Ľڵ�����
		return NULL;
	}
	else if(count==1&&pre!=NULL){//�ж����һ���ڵ��ǲ���ֻ������һ�� 
	    pre->next=cur;
	}
	else if(count>1&&pre!=NULL){
	    pre->next=NULL;
	}
	return head;	
}
