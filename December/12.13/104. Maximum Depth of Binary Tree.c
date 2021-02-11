/*
104. Maximum Depth of Binary Tree
Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/
#include<stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left; 
    struct TreeNode *right;
};


int maxDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    int l = 0, r = 0;
    l = maxDepth(root->left);
    r = maxDepth(root->right);
    return l > r ? l + 1 : r + 1;
}