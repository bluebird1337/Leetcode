// https://leetcode.com/problems/decode-ways/

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int size = s.size();
        vector<int>dp(size+1, 0);
        dp[0] = 1;
        if (s[0] == '0')
            return 0;
        else
            dp[1] = 1;
        for (int i = 1; i < size; i++) {
            if (s[i] != '0')
                dp[i + 1] += dp[i];
            if (s[i - 1] == '1')
                dp[i + 1] += dp[i - 1];
            if (s[i - 1] == '2' && s[i] < '7')
                dp[i + 1] += dp[i - 1];
        }
        return dp[size];
    }
};
