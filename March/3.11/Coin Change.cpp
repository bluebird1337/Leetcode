//https://leetcode.com/problems/coin-change/

#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int>DP(amount + 1, -1);
        DP[0] = 0;
        int num = coins.size();
        sort(coins.begin(), coins.end());
        for (int i = 1; i <= amount; i++) {
            int min = INT_MAX;
            for (int c = 0; c < num; c++) {
                if (i < coins[c])
                    break;
                if (DP[i - coins[c]] != -1)
                    min = min < DP[i - coins[c]] + 1 ? min : DP[i - coins[c]] + 1;
            }
            if (min != INT_MAX)
                DP[i] = min;
        }
        return DP[amount];
    }
};


