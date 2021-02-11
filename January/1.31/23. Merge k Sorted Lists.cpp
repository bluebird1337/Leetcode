//https://leetcode.com/problems/merge-k-sorted-lists/

#include <iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;



//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


typedef ListNode node;
class Solution {
public:
    bool reach_end(vector<ListNode*>lists) {
        for (auto ptr : lists) {
            if (ptr != NULL)
                return true;
        }
        return false;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        node* res = NULL, * p = NULL;
        int size = lists.size();

        while (reach_end(lists)) {
            //find smallest node in lists
            node* smallest = new node;
            smallest->val = INT_MAX;
            int small = 0;
            for (int i = 0; i < size; i++) {
                if (lists[i] == NULL) continue;
                if (lists[i]->val < smallest->val) {
                    smallest = lists[i];
                    small = i;
                }
            }
            //insert smallest into res 
            node* tmp = new node;
            tmp->val = smallest->val;
            if (res == NULL) {//first node
                res = new node;
                res->val = tmp->val;
                p = res;
            }
            else {
                p->next = tmp;
                p = p->next;
            }
            //move smallest to its next
            lists[small] = lists[small]->next;
        }
        return res;
    }
};

int main() {
    vector<ListNode*>list;
    node* tmp = new node;
    tmp->val = 1;
    tmp->next = new node;
    tmp->next->val = 4;
    tmp->next->next = new node;
    tmp->next->next->val = 5;
    list.push_back(tmp);

    node* tmp2 = new node;
    tmp2->val = 1;
    tmp2->next = new node;
    tmp2->next->val = 3;
    tmp2->next->next = new node;
    tmp2->next->next->val = 4;
    list.push_back(tmp2);

    node* tmp3 = new node;
    tmp3->val = 2;
    tmp3->next = new node;
    tmp3->next->val = 6;
    list.push_back(tmp3);
    
    Solution a;
    a.mergeKLists(list);
    return 0;
}