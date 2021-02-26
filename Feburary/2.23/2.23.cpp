// 

#include <iostream>
#include<vector>
#include<algorithm>
#include <map>
using namespace std;


class Solution {
public:
    bool canForm(string s, string ss) {
        int tmp = 0;
        for (auto c : s) {
            if (c == ss[tmp])
                tmp++;
        }
        return tmp == ss.size();
    }

    string findLongestWord(string s, vector<string>& d) {
        map<char, vector<string>>mp;
        for (string dic : d) {
            char first = dic[0];
            mp[first].push_back(dic);
        }
        for (auto iter = mp.begin(); iter != mp.end(); iter++) {
            sort(iter->second.begin(), iter->second.end(), [](string a, string b) {return a.size() < b.size(); });
        }
        int len = 0;
        string res = "";
        string alphabet = "abcdefghijklmnopqrstuvwxyz";
        for (char c : alphabet) {
            if (mp.find(c) == mp.end()) continue;
            vector<string>tmp = mp[c];
            for (auto iter = tmp.rbegin(); iter != tmp.rend(); iter++) {
                if ((*iter).length() <= len) break;
                if (canForm(s, *iter)) {
                    res = *iter;
                    len = (*iter).length();
                }
            }
        }
        return res;
    }
};  

