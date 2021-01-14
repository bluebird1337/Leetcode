/*



You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
*/
 // Definition for singly-linked list.
#pragma warning(disable:6011)
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode node;
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    node* res, * p = NULL;
    res = (node*)malloc(sizeof(node));
    res->next = NULL;
    int c = 0, sum;
    while (l1 || l2) {
        sum = 0;
        if (p == NULL)
            p = res;
        else {
            p->next = (node*)malloc(sizeof(node));
            p->next->next = NULL;
            p = p->next;
        }

        if (l1) {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
        }
        sum += c;
        c = sum < 10 ? 0 : 1;
        p->val = sum < 10 ? sum : (sum - 10);
    }
    if (c == 1) {
        p->next = (node*)malloc(sizeof(node));
        p->next->val = 1;
        p->next->next = NULL;
    }
    return res;
}