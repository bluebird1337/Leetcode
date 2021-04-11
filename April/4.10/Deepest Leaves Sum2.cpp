// https://leetcode.com/problems/deepest-leaves-sum/

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    typedef TreeNode node;
    int deepestLeavesSum(TreeNode* root) {
        int res = 0;
        queue<node*>q;
        q.push(root);
        while (!q.empty()) {
            res = 0;
            int size = q.size();
            while (size) {
                node* tmp = q.front();
                q.pop();
                res += tmp->val;
                if (tmp->left)
                    q.push(tmp->left);
                if (tmp->right)
                    q.push(tmp->right);
                size--;
            }
        }
        return res;
    }
};
