//https://leetcode.com/problems/linked-list-cycle/

#include <iostream>
// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    typedef ListNode node;
    bool hasCycle(ListNode* head) {
        if (!head) return false;
        node* p = head, * q = head;
        while (!p && !q && p != q) {
            p = p->next, q = q->next;
            if (p) p = p->next;
        }
        if (!p || !q) return false;
        return true;
    }
};

