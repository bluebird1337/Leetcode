// https://leetcode.com/problems/deepest-leaves-sum/

#include <bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


class Solution {
public:
    typedef TreeNode node;

    int height(int h, node* tmp) {
        if (tmp == NULL)
            return h;
        int l = height(h + 1, tmp->left);
        int r = height(h + 1, tmp->right);
        return l > r ? l : r;
    }

    void sum_up(int& res, int h, int d, node* tmp) {
        if (h == d - 1 || tmp == NULL) {
            if(h == d - 1 && tmp != NULL)
                res += tmp->val;
            return;
        }
        sum_up(res, h+1, d, tmp->left);
        sum_up(res, h+1, d, tmp->right);
    }

    int deepestLeavesSum(TreeNode* root) {
        int res = 0;
        int d = height(0, root);
        sum_up(res, 0, d, root);
        return res;
    }
};
