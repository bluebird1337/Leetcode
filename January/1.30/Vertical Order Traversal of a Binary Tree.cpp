//https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/?fbclid=IwAR0F-66iH_aooIO1X-GXzzkK9PJmYP2sMpyVNIiy2O6-QyJZmB59vtb8mq4

#include <iostream>
#include<map>
#include<vector>
#include <algorithm> 
using namespace std;

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
    typedef pair<int, int> p;
    typedef map<int, vector<p>> mp;
    typedef TreeNode* tn;
    mp tab;
    void dfs(tn node, int x, int depth) {
        tab[x].push_back({ depth, node->val });
        if (node->left) dfs(node->left, x - 1, depth + 1);
        if (node->right) dfs(node->right, x + 1, depth + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root, 0, 0);
        mp::iterator it = tab.begin();
        vector<vector<int>> ans;
        while (it != tab.end()) {
            sort(it->second.begin(), it->second.end(), [](p a, p b) {
                return a.first == b.first ? a.second < b.second : a.first < b.first;
                });
            vector<int> temp;
            for (auto& i : it->second) temp.push_back(i.second);
            it++;
            ans.push_back(temp);
        }
        return ans;
    }
};

