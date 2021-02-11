//https://leetcode.com/problems/combination-sum/

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void dfs(int target, int start, vector<int>candidates, vector<vector<int>>& res, vector<int>& tmp) {
        if (target == 0) {
            res.push_back(tmp);
            return;
        }
        for (int i = start; i<candidates.size() && target >= candidates[i]; i++) {
            tmp.push_back(candidates[i]);
            dfs(target - candidates[i], i, candidates, res, tmp);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> tmp;
        dfs(target, 0, candidates, res, tmp);
        return res;
    }
};
