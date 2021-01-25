//https://leetcode.com/problems/merge-k-sorted-lists/
//Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
 };
 

#include<stdio.h>

typedef struct ListNode node;
node* merge_two_list(node* l1, node* l2) {
    if (l1 == NULL)
        return l2;
    else if (l2 == NULL)
        return l1;
    else if (l1->val < l2->val) {
        l1->next = merge_two_list(l1->next, l2);
        return l1;
    }
    else {
        l2->next = merge_two_list(l1, l2->next);
        return l2;
    }
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0)
        return NULL;
    if (listsSize == 1)
        return lists[0];

    int i = 0, j = listsSize - 1;
    while (i < j) {
        for (; i < j; i++, j--) {
            lists[i] = merge_two_list(lists[i], lists[j]);
            listsSize--;
        }
        i = 0, j = listsSize - 1;
    }
    return lists[0];
}