#include<iostream>
#include<vector>
#include<unordered_map>


using namespace std;



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head=nullptr;
        ListNode *p=nullptr;
        int carry = 0;
        while(l1 || l2 || carry){
            int n1=l1?l1->val : 0;
            int n2=l2?l2->val : 0;
            int sum = (carry+n1+n2)%10;
            carry = (carry+n1+n2)/10;

            if(!head){
                head = p = new ListNode(sum);
            }
            else {
                p->next = new ListNode(sum);
                p = p->next;
            }

            if(l1)  l1=l1->next;
            if(l2)  l2=l2->next;
        }

        return head;
    }
};