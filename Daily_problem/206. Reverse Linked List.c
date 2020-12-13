#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
 

struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
        return head;
    struct ListNode* p = NULL, * q = head, * r = head->next;
    while (r) {
        p = q, q = r, r = r->next;
        if (p == head)
            p->next = NULL;
        q->next = p;
    }
    q->next = p;
    head = q;
    return head;
}