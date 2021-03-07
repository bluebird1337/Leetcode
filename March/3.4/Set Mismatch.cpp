// https://leetcode.com/problems/set-mismatch/

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int>res;
        int dup=-1, total = (n + 1) * n / 2;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                dup = nums[i];
                break;
            }
        }
        total -= dup;
        for (int i = 0; i < n; i++) {
            if (nums[i] == dup)
                continue;
            else
                total -= nums[i];
        }
        res.push_back(dup);
        res.push_back(total);
        return res;
    }
};

