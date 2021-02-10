// https://leetcode.com/problems/convert-bst-to-greater-tree/

#include <iostream>
#include<vector>
#include <utility> 
#include<algorithm>
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
 private:
     int sum = 0;
 public:
     void traverse(TreeNode*p) {
         if (!p) return;
         if (p->right) traverse(p->right);
         sum += p->val;
         p->val = sum;
         if (p->left) traverse(p->left);
     }
     TreeNode* convertBST(TreeNode* root) {
         traverse(root);
         return root;
     }
 };

 /*
typedef TreeNode node;
class Solution {
public:
    int search(int target, vector<pair<int, int>>track) {
        //return the value thay target need to add: 
        int l = 0, r = track.size();
        int m;
        //if found same value return it, if not, return the value of nearest to add
        while (l <= r) {
            m = l + (r - l) / 2;
            if (track[m].first < target)
                l = m + 1;
            else if (track[m].first > target)
                r = m;
            else // found
                return track[m].second;
        }
        //not found, track[m] != target
        if (track[m].first < target)
            return track[m + 1].second + track[m + 1].first;
        else
            return track[m].second + track[m].first;
    }
    TreeNode* convertBST(TreeNode* root) {
        //iterate through entire tree, store all value in a vector<int, int>, second initialize as -1
        vector<pair<int, int>>track;
        node* p = root;
        vector<node*>stack;
        while (p || !stack.empty()) {
            if (p != NULL) {
                track.push_back(make_pair(p->val, -1));
                stack.push_back(p);
                p = p->left;
            }
            else {
                p = stack.back();
                stack.pop_back();
                p = p->right;
            }
        }
        //sort the vector
        sort(track.begin(), track.end(), [](pair<int, int>a, pair<int, int>b) {return a.first < b.first; });
        //from back to front, keep track the sum of current sum that should add onto this first value, vector[0]->second:sum of total tree except itself, vector[size]->second:0
        int sum = 0, size = track.size();
        for (int i = size - 1; i >= 0; i--) {
            track[i].second = sum;
            sum += track[i].first;
        }
        //iterate through the whole tree, search each node's value, plus it and renew the tree
        stack.clear();
        p = root;
        while (p || !stack.empty()) {
            if (p != NULL) {
                p->val += search(p->val, track);
                stack.push_back(p);
                p = p->left;
            }
            else {
                p = stack.back();
                stack.pop_back();
                p = p->right;
            }
        }
        return root;
    }
};
*/