#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
 * Definition for singly-linked list.
  struct ListNode {
      int val;
      struct ListNode *next;
  };
 */

struct ListNode {
      int val;
      struct ListNode *next;
  };
 struct ListNode* reverse(struct ListNode* head){
	if(head==NULL){
		return NULL;
	}
	struct ListNode *pre=NULL;
	struct ListNode *cur=head;
	struct ListNode *next=NULL;
	while(cur){
		next=cur->next;
		cur->next=pre;
		pre=cur;
		cur=next;
	}
	return pre;
	
}
struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    if(head==NULL||m<0||n<0||m>n){//有效性检查 
    	return NULL;
	} 
	if(m==n){
		return head;
	}
	//先求链表的长度，判断m和n的取值是否在长度范围之内 
	struct ListNode *cur1=head;
	int len=0;
	while(cur1){
		len++;
		cur1=cur1->next;
	}
	if(m>len||n>len){//m和n的长度不能大于链表中节点的个数 
		return NULL;
	}
	cur1=head;//cur节点重新指向头结点 
	int mm=m;//保存下m的值 
	struct ListNode *pre=NULL;
	while(m>1){//找到要翻转的前一个节点pre和第一个结点cur1 
		pre=cur1; 
		cur1=cur1->next; 
		m--;		
	} 
	struct ListNode *cur2=cur1;
	while(cur2!=NULL&&n>mm){//使得cur2指向翻转指针的第一个结点 
		cur2=cur2->next;
		n--;
	}
	struct ListNode *next=cur2->next; //要翻转的最后的一个节点的下一个节点 ，为后续的连接做准备 
	//开始翻转,先断开m~n节点作为即将要翻转的链表 
	//先判断下pre是否为空，即当m=1时为空;如果不为空，则不做处理 
	if(pre){
		pre->next=NULL;
		
	} 
	cur2->next=NULL; 
	
	//开始翻转
	struct ListNode *newHead=reverse(cur1);
	//连接起来
	//先判断下pre是否为空，若为空，则newHead就是第一个结点 
	if(pre){
		pre->next=newHead;
		
	}
	else{
	    //若为空，则newHead为头结点
	    head=newHead; 
	}
//	pre=newHead;

	//连接next后面的节点连接起来 
	while(newHead!=NULL){
		pre=newHead;
		newHead=newHead->next;
	} 
	
	 pre->next=next;
	 
	
	return head;	 
}
#define N  3
int main(void){
	struct ListNode *head=(struct ListNode *)malloc(sizeof(ListNode ));
	if(head==NULL){
		exit(EXIT_FAILURE);
	}
	head->val=4;
	struct ListNode *node1=(struct ListNode *)malloc(sizeof(ListNode ));
	node1->val=9;
	head->next=node1;
	struct ListNode *node2=(struct ListNode *)malloc(sizeof(ListNode ));
	node2->val=2;
	node1->next=node2;
	node2->next=NULL;
	ListNode *result=reverseBetween( head, 2, 3);
	while(result){
	 	printf("%d  ",  result->val);
	 	result=result->next;
	 }
	
	return 0;
} 
