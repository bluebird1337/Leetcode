//https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

#include <iostream>
#include<vector>
using namespace std;


//Definition for a binary tree node.
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
    node* helper(vector<int>pre, vector<int>in, int&index, int left, int right) {
        if (left > right)
            return NULL;
        int pivot = left;
        while (pre[index] != in[pivot])
            pivot++;
        index++;
        node* p = new node;
        p->val = in[pivot];
        p->left = helper(pre, in, index, left, pivot - 1);
        p->right = helper(pre, in, index, pivot + 1, right);
        return p;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        return helper(preorder, inorder, index, 0, inorder.size() - 1);
    }
};
