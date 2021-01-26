//https://leetcode.com/problems/two-sum/

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>res;
        int new_target;
        for (int i = 0; i < nums.size(); i++) {
            new_target = target - nums[i];
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] == new_target) {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
        return res;
    }
};