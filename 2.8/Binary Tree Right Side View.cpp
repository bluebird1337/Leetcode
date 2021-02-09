// https://leetcode.com/problems/binary-tree-right-side-view/

#include <iostream>
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
 
typedef TreeNode node;
class Solution {
public:
    void traverse(node* p, int currheight, int& maxheight, vector<int>& res) {
        if (currheight > maxheight) {
            res.push_back(p->val);
            maxheight = currheight;
        }
        if (p->right) traverse(p->right, currheight + 1, maxheight, res);
        if (p->left) traverse(p->left, currheight + 1, maxheight, res);
    }

    vector<int> rightSideView(TreeNode* root) {
        int maxheight = -1;
        vector<int>res;
        if (root == NULL) return res;
        traverse(root, 0, maxheight, res);
        return res;
    }
};