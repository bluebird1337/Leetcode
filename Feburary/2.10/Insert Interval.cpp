//https://leetcode.com/problems/insert-interval/


#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>res;
        int size = intervals.size();
        if (size == 0) {
            res.push_back(newInterval);
            return res;
        }
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        res.push_back(intervals[0]);
        for (int i = 1; i <= size; i++) {
            if (res.back()[1] < intervals[i][0])
                res.push_back(intervals[i]);
            else 
                res.back()[1] = max(res.back()[1], intervals[i][1]);
        }
        return res;
    }
};
