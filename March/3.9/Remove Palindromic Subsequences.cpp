// https://leetcode.com/problems/remove-palindromic-subsequences/

#include <iostream>
using namespace std;

class Solution {
public:
    int removePalindromeSub(string s) {
        return 2 - (s == string(s.rbegin(), s.rend())) - s.empty();
    }
};