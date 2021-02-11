//https://leetcode.com/problems/combination-sum-iii/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void find(int n, int k, vector<vector<int>>& res, vector<int> tmp) {
        if (tmp.size() == k && n == 0) {
            res.push_back(tmp);
            return;
        }
        else {
            for (int i = tmp.size() == 0 ? 1 : tmp.back() + 1; i <= 9; i++) {
                tmp.push_back(i);
                find(n - i, k, res, tmp);
                tmp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>res;
        vector<int>tmp;
        find(n, k, res, tmp);
        return res;
    }
};

int main() {
    Solution a;
    vector<vector<int>> ans;
    ans = a.combinationSum3(3, 7);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}