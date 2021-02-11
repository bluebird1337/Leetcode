//https://leetcode.com/problems/unique-paths/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        if (m == 1 && n == 1)
            return 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!i && !j)
                    dp[i][j] = 0;
                else if ((!i && j) || (i && !j)) {
                    dp[i][j] = 1;
                }
                else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
