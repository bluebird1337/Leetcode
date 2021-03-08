//https://leetcode.com/problems/binary-tree-level-order-traversal/

#include<iostream>
#include<queue>
#include<vector>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<node*>q;
        vector<vector<int>>res;
        if (!root)
            return res;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int>tmp;
            for (int i = 0; i < size; i++) {
                node* p = q.front();
                q.pop();
                if (p->left)
                    q.push(p->left);
                if (p->right)
                    q.push(p->right);
                tmp.push_back(p->val);
            }
            res.push_back(tmp);
        }
        return res;
    }
};
