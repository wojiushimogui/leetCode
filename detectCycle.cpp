


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/*
思路:先用两个指针来进行遍历判断是否有环 ,一个只移动一个节点，一个移动两个节点 ；
如果没有环，输出NULL即可。如果有环，则断开环，将其转化为求两个链表的第一个公共节点问题 
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
	
	//如果运行到这里，就说明链表中有环出现
	//第一步：断开环，将其转化为两个链表
	struct ListNode *head1=oneStep->next;
	oneStep->next=NULL;
	//第二步：求两个链表的第一个公共节点
	//先求两个链表的长度
	int len1=length_list(head);
	int len2=length_list(head1); 
	//将较长的链表移动abs(len1-len2)个长度
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
