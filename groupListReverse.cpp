/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/*
思路：先写一个关于长度为k的链表翻转，然后利用递归将其求解
*/
/*
参数的说明：
@param head：链表的头结点
@param n:链表中结点的个数
返回值：返回链表的头结点
*/
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
      int val;
      struct ListNode *next;
  };
struct ListNode *reverseList(struct ListNode *head,int n){
    if(head==NULL||n<1){
        return NULL;
    }
    struct ListNode *print=head;
    while(print!=NULL){
		printf("翻转前%d  ",print->val);
		print=print->next;
	} 
    struct ListNode *pre=NULL;
    struct ListNode *cur=head;
    struct ListNode *next=NULL;
    for(int i=0;i<n-1;i++){
        next=cur->next;//保存下一个结点指针
        cur->next=pre;
        pre=cur;
        cur=next;//
    }
    //for循环结束时，cur指向原链表的最后一个结点。即新链表的头结点
    cur->next=pre;
    
    struct ListNode *printNode=cur;
	while(printNode!=NULL){
		printf("翻转后%d  ",printNode->val);
		printNode=printNode->next;
	} 
    
    return cur;
    
}
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if(head==NULL||k<0){
        return NULL;
    }
    //先求链表的长度
    struct ListNode *temp=head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    if(k>len){//当k大于链表长度时，返回原链表头结点
        return head;
    }
    if(k==1){//不翻转，直接返回 
    	return head;
	}
    //开始按k个借点为一组来进行翻转
    struct ListNode *cur=head;
    struct ListNode *pre=NULL; 
    struct ListNode *curHead=head;
    struct ListNode *nextHead=NULL;
    struct ListNode **allHead=(struct ListNode **)malloc((len/k)*sizeof(struct ListNode *));
    if(allHead==NULL){
        exit(EXIT_FAILURE);
    }
    int index=0;
    int count=len/k;
    for(int i=0;i<count;i++){
        //以k个结点为段，保存下一个即将要翻转的头结点
        for(int i=0;i<k;i++){
        	pre=cur;
            cur=cur->next;//下一轮的头结点
        }
        //先将头一段翻转
        pre->next=NULL;
        
        allHead[index]=reverseList(curHead,k);
        index++;
        //问题再这里：为什么没有变呢？？？ 
        curHead=cur;
    }//此for循环结束的时候，curHead指向最后没有翻转的剩余结点的头结点
    
    //最后将这所有链表拼接起来就ok了
    struct ListNode *newListHead=allHead[0];
    struct ListNode *node=allHead[0];
    for(int i=0;i<index;i++){
        for(int j=0;j<k-1;j++){//使node指向最后一个结点
            node=node->next;
        }
        if(i!=index-1){
            node->next=allHead[i+1];
            node=node->next;//使的结点指向后一段的头结点 
        }
        else{
            node->next=curHead;
        }
        
    }
    return newListHead;
      
}
int main(void){
	//创建一个链表
	ListNode *node1=(ListNode *)malloc(sizeof(ListNode)); 
	ListNode *node2=(ListNode *)malloc(sizeof(ListNode)); 
	ListNode *node3=(ListNode *)malloc(sizeof(ListNode)); 
	ListNode *node4=(ListNode *)malloc(sizeof(ListNode)); 
	ListNode *node5=(ListNode *)malloc(sizeof(ListNode)); 
	node1->val=8;
	node1->next=node2;
	node2->val=7;
	node2->next=node3;
	node3->next=node4;
	node3->val=3;
	node4->next=node5;
	node4->val=5;
	node5->next=NULL;
	node5->val=18;
	ListNode *head=reverseKGroup(node1,2);
	printf("\n");
	while(head!=NULL){
		printf("%d   ",head->val);
		head=head->next;
	}
	
//	ListNode *head=(ListNode *)malloc(sizeof(ListNode)); 
				
	return 0;
}
