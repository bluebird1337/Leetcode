//https://leetcode.com/problems/global-and-local-inversions/
#include<bits/stdc++.h>
using namespace std;

#define M(a, b) a>b?a:b
class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int sz = nums.size();
        int max = -1;
        for (int i = 0; i < sz - 2; i++) {
            max = M(nums[i], max);
            if (max > nums[i + 2])
                return false;
        }
        return true;
    }
};
