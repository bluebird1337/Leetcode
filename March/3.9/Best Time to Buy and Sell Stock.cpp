//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        vector<int>DP(size, 0);
        int min = prices[0], res = 0;
        for (int i = 1; i < size; i++) {
            if (prices[i] > min)
                DP[i] = prices[i] - min;
            res = res > DP[i] ? res : DP[i];
            min = min < prices[i] ? min : prices[i];
        }
        return res;
    }
};
