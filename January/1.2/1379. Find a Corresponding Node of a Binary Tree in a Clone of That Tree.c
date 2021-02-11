#pragma warning(disable:6011)
#include<stdio.h>
#include<stdlib.h>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* ans = NULL;
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (cloned) {
            if (original == target) {
                ans = cloned;
            }
            else {
                getTargetCopy(original->left, cloned->left, target);
                getTargetCopy(original->right, cloned->right, target);
            }
        }
        return ans;
    }
};
