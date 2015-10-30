/*
You are given two linked lists representing two non-negative numbers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

*/ 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
//  Definition for singly-linked list.
  struct ListNode {
      int val;
      struct ListNode *next;
  };
 
 int list_len(struct ListNode* list){
     if(list==NULL){
         return 0;
     }
     int len=1;
     while(list->next!=NULL){
         len++;
     }
     return len;
     
 }
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if(l1==NULL){//有效性检查
        return l2;
    }
    if(l2==NULL){
        return l1;
    }
    //求出两个链表的长度
    int len1=list_len(l1);
    int len2=list_len(l2);
    //长链表代表大的数，短链表代表小的数
    ListNode* highNum=l1;
    ListNode* lowNum=l2;
    int highLen=len1;
    int lowLen=len2;
    if(len1<len2){
        highNum=l2;
        lowNum=l1;
        highLen=len2;
        lowLen=len1;
    }
    int ci=0;//表示进位
    ListNode* cur1=highNum;
    ListNode* cur2=lowNum;
    ListNode* pre1=NULL;
    while(lowLen>0){
        int temp=cur1->val+cur2->val+ci;
        cur1->val=temp%10;
        ci=temp/10;
        pre=cur1;
        cur1=cur1->next;
        cur2=cur2->next;
        lowLen--;
        highLen--;
        
    }
    //将最后一个进位与长链表中剩余的结点相加
    if(highLen>0&&ci>0){
        
        while(highLen>0){
            int temp=cur1->val+ci;
            cur1->val=temp%10;
            ci=temp/10;
            pre=cur1;
            cur1=cur->next;
            highLen--;
        }
        if(ci>0){//需要创建新的结点
            ListNode *newNode=(ListNode *)malloc(sizeof(ListNode));
            if(newNode==NULL)
                exit(EXIT_FAILURE);
            newNode->val=ci;
            newNode->next=NULL;
            pre->next=newNode;
            
            
        }
    }
    else if(highLen==0&&ci>0){
            ListNode *newNode=(ListNode *)malloc(sizeof(ListNode));
            if(newNode==NULL)
                exit(EXIT_FAILURE);
            newNode->val=ci;
            newNode->next=NULL;
            pre->next=newNode;
            
    }
    return highNum;
    
    
    
}
