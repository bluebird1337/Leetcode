// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int curr_min = INT_MAX, curr_max = INT_MIN, start = -1, end, size = nums.size();
        for (int i = size - 1; i >= 0; i--) {
            if (nums[i] < curr_min) 
                curr_min = nums[i];
            if (nums[i] > curr_min)
                start = i;
        }
        for (int i = 0; i < size; i++) {
            if (nums[i] > curr_max)
                curr_max = nums[i];
            if (nums[i] < curr_max)
                end = i;
        }
        return start == -1 ? 0 : end - start + 1;
    }
};

