// https://leetcode.com/problems/valid-anagram/

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std; 

class Solution {
public:
    bool isAnagram(string s, string t) {
        int size = s.length();
        int size2 = t.length();
        if (size != size2)
            return false;
        vector<int>tmp, tmp2;
        for (int i = 0; i < size; i++) {
            tmp.push_back((int)s[i]);
            tmp2.push_back((int)t[i]);
        }
        sort(tmp.begin(), tmp.end());
        sort(tmp2.begin(), tmp2.end());
        for (int i = 0; i < size; i++) {
            if (tmp[i] != tmp2[i])
                return false;
        }
        return true;
    }
};

