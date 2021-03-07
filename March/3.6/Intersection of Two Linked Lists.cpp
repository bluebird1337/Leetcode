//https://leetcode.com/problems/intersection-of-two-linked-lists/

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    typedef ListNode node;
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        node* p = headA, * q = headB;
        while (p || q) {
            if (p == q)
                return p;
            p = p == NULL ? headB : p->next;
            q = q == NULL ? headA : q->next;
        }
        return NULL;
    }
};