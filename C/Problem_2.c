/*
2. 两数相加

给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
请你将两个数相加，并以相同形式返回一个表示和的链表。
你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// 我的解答，节点的 管理/连接 可以用 p+tail ,也可以用 tail+tail->next连接
// 总而言之，链表一定要有节点连接的过程：tail->next = p, tail = p;
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0;
    struct ListNode *p1 = l1;
    struct ListNode *p2 = l2;
    int sum = 0;
    struct ListNode *head = NULL;
    struct ListNode *p = NULL;
    struct ListNode *tail =NULL;


    while(p1 != NULL && p2 != NULL){
        sum = (carry + p1->val + p2->val)%10;
        carry = (carry + p1->val + p2->val)/10;
        p = malloc(sizeof(struct ListNode));
        p->next = NULL;
        p->val = sum;
        if(!head) {
            head = p;
            tail = p;
        }else{
            tail->next = p;
            tail = p;
        }
        p1 = p1->next;
        p2 = p2->next;
    }



    while(p1 != NULL){
        sum = (carry + p1->val)%10;
        carry = (carry + p1->val)/10;
        p = malloc(sizeof(struct ListNode));
        p->val = sum;
        p->next = NULL;
        tail->next = p;
        tail = p;
        p1 = p1->next;
    }

    while(p2 != NULL){
        sum = (carry + p2->val)%10;
        carry = (carry + p2->val)/10;
        p = malloc(sizeof(struct ListNode));
        p->val = sum;
        p->next = NULL;

        tail->next = p;
        tail = p;
        p2 = p2->next;
    }

    if(carry != 0){
        p = malloc(sizeof(struct ListNode));
        p->val = carry;
        p->next = NULL;
        tail->next = p;
        tail = p;
    }
    return head;
}