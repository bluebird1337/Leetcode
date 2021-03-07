//https://leetcode.com/problems/average-of-levels-in-binary-tree/

#include <iostream>
#include<vector>
#include<queue>
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>res;
        queue<node*>q;
        q.push(root);
        while (!q.empty()) {
            double size = q.size();
            double sum = 0;
            for (int i = 0; i < size; i++) {
                node* tmp = q.front();
                q.pop();
                sum += tmp->val;
                if (tmp->left)
                    q.push(tmp->left);
                if (tmp->right)
                    q.push(tmp->right);
            }
            double aver = sum / size;
            res.push_back(aver);
        }
        return res;
    }
};

