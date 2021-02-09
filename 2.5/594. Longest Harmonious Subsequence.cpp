//https://leetcode.com/problems/longest-harmonious-subsequence/

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0, currnum = 1, nextnum = 0, nextIDX = 1, currval = nums[0], i = 1, size = nums.size();
        if (size == 1) return 0;
        while (i < size) {
            if (nums[i] == currval) {
                i++, currnum++;
            }
            else {
                if (nums[nextIDX] <= currval)
                    nextIDX = i;
                if (nums[i] - currval == 1) {
                    nextnum++, i++;
                }
                else {
                    if (nextIDX == i) i++;
                    if (nums[nextIDX] - currval <= 1)
                        res = max(res, currnum + nextnum);
                    currnum = nextnum > 0 ? nextnum : 1;
                    nextnum = 0;
                    currval = nums[nextIDX];
                    nextIDX = 0;
                }
            }
        }
        if ( abs(nums[nextIDX] - currval) <= 1)
            res = max(res, currnum + nextnum);
        if (currnum == size) return 0;
        return res;
    }
};

