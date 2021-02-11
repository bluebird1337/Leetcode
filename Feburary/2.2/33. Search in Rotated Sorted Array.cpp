//https://leetcode.com/problems/search-in-rotated-sorted-array/


#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int bs(int l, int r, int target, vector<int>nums) {
        int res = -1 ;
        while (l <= r) {
            int m = l + (r - l) / 2;

            if (nums[m] > target) 
                r = m - 1;
            else if (nums[m] < target) 
                l = m + 1;
            else {
                res = m;
                break;
            }
        }
        return res;
    }
    int search(vector<int>& nums, int target) {
        int p = 0, res;
        int size = nums.size();
        while (nums[p] > nums[size - 1])p++;
        if (target > nums[size - 1])
            res = bs(0, p - 1, target, nums);
        else
            res = bs(p, size - 1, target, nums);
        return res;
    }
};

