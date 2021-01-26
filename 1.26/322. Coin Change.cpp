//https://leetcode.com/problems/coin-change/

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<int>dp;
        dp.push_back(0);
        int i;
        for (i = 1; i <= amount; i++) {
            dp.push_back(INT_MAX);

            for (int c : coins) {
                if (c > i)
                    break;
                if (dp[i - c] != INT_MAX)
                    dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};

