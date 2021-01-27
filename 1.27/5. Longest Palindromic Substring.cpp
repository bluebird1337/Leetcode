//https://leetcode.com/problems/longest-palindromic-substring/
#include <iostream>
#include<vector>
#include <string>
using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        int p, max_len = 0;
        string res;
        for (p = 0; p < len ; p++) {
            int tmp = 1;
            if (p == 0) {
                max_len = 1;
                res = s.substr(0, 1);
                continue;
            }
            else if (p == len-1) {
                int j = p - 1;
                while (j >= 0 && s[j] == s[p]) {
                    tmp++, j--;
                }
                if (max_len < tmp) {
                    res = s.substr(j + 1, tmp);
                }
            }
            else {
                int i = p - 1, j = p + 1;
                while (i >= 0 && s[i] == s[p]) {
                    tmp++, i--;
                }
                while (j < len && s[j] == s[p]) {
                    tmp++, j++;
                }
                while (i >= 0 && j < len && s[i] == s[j]) {
                    i--, j++, tmp += 2;
                }
                if (max_len < tmp) {
                    max_len = tmp;
                    res = s.substr(i + 1, tmp);
                }
            }
        }
        return res;
    }
};