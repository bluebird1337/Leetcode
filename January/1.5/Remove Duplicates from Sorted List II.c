#include<stdio.h>
/*Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.*/

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode node;

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL)
        return NULL;

    node* last = head, * back = NULL;
    while (last && last->next) { // out of this loop mean last is the last node
        if (last->val != last->next->val) {
            back = last;
            last = last->next;
        }
        else {
            if (last == head) { // need to move head
                while (last && last->next && last->val == last->next->val) {
                    last = last->next;
                }
                last = last->next;
                head = last;
            }
            else {
                while (last->val == last->next->val) {
                    last = last->next;
                }
                last = last->next;
                back->next = last;
            }
        }
    }
    return head;
}