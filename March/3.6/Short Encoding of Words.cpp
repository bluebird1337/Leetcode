// https://leetcode.com/problems/short-encoding-of-words/

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        string res = "";
        sort(words.begin(), words.end(), []
        (string str1, string str2) {
                return str1.size() > str2.size();
            });
        int size = words.size();
        res += words[0] + '#';

        for (int i = 1; i < size; i++) {
            string tmp = words[i] + '#';
            int pos = res.find(tmp);
            if (pos != -1)
                continue;
            res += tmp;
        }
        return res.size();
    }
};
