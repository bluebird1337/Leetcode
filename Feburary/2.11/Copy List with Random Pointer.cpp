// https://leetcode.com/problems/copy-list-with-random-pointer/

#include <iostream>

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        //Step 1 : copy the list except for random pointer
        Node* p = head;
        while (p) {
            Node* tmp = new Node(p->val);
            tmp->next = p->next;
            p->next = tmp;
            p = p->next->next;
        }
        //Step 2 : copy the random pointer
        p = head;
        while (p) {
            if (p->random) {
                p->next->random = p->random->next;
            }
            p = p->next->next;
        }
        //Step 3 : extract the copy list from the origin list
        Node* res = new Node(0);
        Node* iter = res;
        p = head;
        while (p) {
            iter->next = p->next;
            iter = iter->next;
            p->next = p->next->next;
            p = p->next;
        }
        return res->next;
    }
};

