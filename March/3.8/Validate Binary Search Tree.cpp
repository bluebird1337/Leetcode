//https://leetcode.com/problems/validate-binary-search-tree/

#include<iostream>
#include<stack>
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
    bool isValidBST(TreeNode* root) {
        stack<node*>st;
        vector<int>v;
        node* p = root;
        while (p || !st.empty()) {
            if (p) {
                st.push(p);
                p = p->left;
            }
            else {
                p = st.top();
                st.pop();
                v.push_back(p->val);
                p = p->right;
            }
        }
        int small = v[0];
        for (int i = 1; i<v.size() ; i++) {
            if (v[i] <= small)
                return false;
            small = v[i];
        }
        return true;
    }
};
