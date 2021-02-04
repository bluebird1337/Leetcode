//https://leetcode.com/problems/maximum-subarray/

#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int tmp = nums[0];
        int res = nums[0];
        for (int i = 1; i < n; i++) {
            tmp = nums[i] + (tmp > 0 ? tmp : 0);
            res = max(res, tmp);
        }
        return res;
    }
};

