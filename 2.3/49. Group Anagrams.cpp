//https://leetcode.com/problems/group-anagrams/

#include <iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

class Solution {
public:
    string generate_key(string s) {
        vector<int>str;
        int len = s.length();
        for (int i = 0; i < len; i++)
            str.push_back((int)s[i]);
        sort(str.begin(), str.end());
        string res;
        for (int i = 0; i < len; i++)
            res.push_back(char(str[i]));
        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>>mp;
        int size = strs.size();
        string key;
        for (int i = 0; i < size; i++) {
            key = generate_key(strs[i]);
            map < string, vector<string>>::iterator it;
            it = mp.find(key);
            if (it != mp.end())
                it->second.push_back(strs[i]);
            else
                mp[key].push_back(strs[i]);
        }
        vector<vector<string>>res;
        for (auto iter = mp.begin(); iter != mp.end(); iter++)
            res.push_back(iter->second);
        return res;
    }
};

int main() {
    Solution a;
    string s = {"ate"};
    cout << a.generate_key(s);

    return 0;
}