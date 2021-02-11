//https://leetcode.com/problems/remove-nth-node-from-end-of-list/

#include <iostream>
#include<unordered_map>
#include<vector>
using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == NULL)
            return NULL;
        ListNode* p = head, * q = head, * t;
        for (int i = 0; i < n; i++) p = p->next;
        if (p == NULL) return head->next;
        else {
            while (p->next) {
                q = q->next;
                p = p->next;
            }
            t = q->next;
            q->next = t->next;
            delete t;
            return head;
        }
        return head;
    }
};

int main() {
    Solution a;
    ListNode* head = new ListNode;
    head->next = new ListNode;
    head->val = 1;
    ListNode* res = a.removeNthFromEnd(head, 1);
    while (res) {
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}