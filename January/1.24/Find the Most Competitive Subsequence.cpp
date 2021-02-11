#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int>stack;
        for (int i = 0; i < nums.size(), i++) {
            while (!stack.empty() && nums[i] < stack.back() && stack.size() + (nums.size() - i) >= k) {
                stack.pop_back();
            }
            if (stack.size() < k) {
                stack.push_back(nums[i]);
            }
        }
        return stack;
    }
};


