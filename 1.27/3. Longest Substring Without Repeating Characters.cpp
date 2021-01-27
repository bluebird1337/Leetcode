//https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = -1;
        for (int i = 0; i < s.size(); i++) {
            vector<int>ASCII(128, 0);
            ASCII[(int)s[i]] = 1;
            int tmp = 1;
            for (int j = i + 1; j < s.size(); j++) {
                if (ASCII[(int)s[j]] != 0)
                    break;
                tmp++;
                ASCII[(int)s[j]] = 1;
            }
            res = res < tmp ? tmp : res;
        }
        return res;
    }
};

