//https://leetcode.com/problems/merge-intervals/
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int size = intervals.size();
        if (size <= 1) return intervals;
        vector<vector<int>>res;
        sort(intervals.begin(), intervals.end(), [](vector<int>a, vector<int>b) {return a[0] > b[0]; });
        res.push_back(intervals[0]);
        for (int i = 1; i < size; i++) {
            if (res.back()[1] >= intervals[i][0])
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            else
                res.push_back(intervals[i]);
        }
        return res;
    }
};

int main() {
    vector<vector<int>>interval = { {1,3},{9,6},{12,10},{6,18} };
    Solution a;
    a.merge(interval);
    return 0;
}