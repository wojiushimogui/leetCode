


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/*
˼·:��������ָ�������б����ж��Ƿ��л� ,һ��ֻ�ƶ�һ���ڵ㣬һ���ƶ������ڵ� ��
���û�л������NULL���ɡ�����л�����Ͽ���������ת��Ϊ����������ĵ�һ�������ڵ����� 
*/
struct ListNode {
      int val;
      struct ListNode *next;
  };
int length_list(struct ListNode *head){	
	struct ListNode *cur=head;
	int len=0;
	while(cur){
		len++;
		cur=cur->next;
	}
	return len;
}
struct ListNode *detectCycle(struct ListNode *head) {
    if(head==NULL||head->next==NULL)  return NULL;
    struct ListNode *oneStep=head;
    struct ListNode *twoStep=head->next ;
    while(oneStep!=twoStep){
    	if(twoStep==NULL||twoStep->next==NULL||oneStep==NULL) return NULL;
    	else{
    		oneStep=oneStep->next;
    		twoStep=twoStep->next->next;
		}
	}
	
	//������е������˵���������л�����
	//��һ�����Ͽ���������ת��Ϊ��������
	struct ListNode *head1=oneStep->next;
	oneStep->next=NULL;
	//�ڶ���������������ĵ�һ�������ڵ�
	//������������ĳ���
	int len1=length_list(head);
	int len2=length_list(head1); 
	//���ϳ��������ƶ�abs(len1-len2)������
	struct ListNode *lengthList=head;
	struct ListNode *lowList=head1; 
	int dif=abs(len1-len2);
	if(len1<len2){
		lengthList=head1;
		lowList=head;
	}
	struct ListNode *cur1=lengthList;
	struct ListNode *cur2=lowList;
	while(dif>0){
		cur1=cur1->next;
		dif--;
	}
	while(cur1&&cur2){
		if(cur1==cur2){
			return cur1;
		}
		cur1=cur1->next;
		cur2=cur2->next;
	}
	return NULL;
}
