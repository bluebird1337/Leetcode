//https://leetcode.com/problems/minimize-deviation-in-array/

#include <iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        set<int>s;
        for (auto& i : nums)
            s.insert(i % 2 == 0 ? i : i * 2);
        int res = *s.rbegin() - *s.begin();
        while (*s.rbegin() % 2 == 0) {
            s.insert(*s.rbegin() / 2);
            s.erase(*s.rbegin());
            res = min(res, *s.rbegin() - *s.begin());
        }
        return res;
    }
};

