// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> res;
    map<char, string>mp = {
    {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7',"pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };
    void dfs(int index, string digits, string tmp) {
        if (index == digits.size()) {
            res.push_back(tmp);
            return;
        }
        char letter = digits[index];
        int size = mp[letter].size();
        for (int i = 0; i < size; i++) {
            tmp.push_back(mp[letter][i]);
            dfs(index + 1, digits, tmp);
            tmp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() != 0)
            dfs(0, digits, "");
        return res;
    }
};
