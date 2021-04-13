#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));
        vector<pair<int, int >>num;
        int sz = strs.size();
        for (int i = 0; i < sz; i++) {
            int num_0 = 0, num_1 = 0;
            for (char c : strs[i]) {
                if (c == '0')
                    num_0++;
                else
                    num_1++;
            }
            num.push_back(make_pair(num_0, num_1));
        }
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                int max = 0;
                for (int k = 0; k < sz; k++) {
                    int num_0 = num[k].first, num_1 = num[k].second;
                    if (i - num_0 >= 0 && j - num_1 >= 0)
                        max = max > dp[i - num_0][j - num_1] + 1 ? max : dp[i - num_0][j - num_1] + 1;
                }
                dp[i][j] = max;
            }
        }
        return dp[m][n];
    }
};

