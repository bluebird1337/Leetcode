// https://leetcode.com/problems/missing-number/

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total = n * (n + 1) / 2;
        for (int num : nums)
            total -= num;
        return total;
    }
};

