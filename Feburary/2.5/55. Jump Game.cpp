//https://leetcode.com/problems/jump-game/

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        int minjump = 0;
        for (int i = size - 2; i >= 0; i--) {
            minjump++;
            if (nums[i] >= minjump) minjump = 0;
        }
        return minjump == 0 ? true : false;
    }
};
