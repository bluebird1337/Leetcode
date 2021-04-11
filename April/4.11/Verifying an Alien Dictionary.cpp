// https://leetcode.com/problems/verifying-an-alien-dictionary/

#include <bits/stdc++.h>
using namespace std;

bool isAlienSorted(vector<string> words, string order) {
    int mapping[26];
    for (int i = 0; i < 26; i++)
        mapping[order[i] - 'a'] = i;
    for (string& w : words)
        for (char& c : w)
            c = mapping[c - 'a'];
    return is_sorted(words.begin(), words.end());
}

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int map[26];
        for (int i = 0; i < 26; i++)
            map[order[i] - 'a'] = i;
        int size = words.size();
        for (int i = 0; i < size - 1; i++) {
            int a = 0;
            while (a < words[i].size() && a < words[i + 1].size() && map[words[i][a] - 'a'] == map[words[i + 1][a] - 'a'])
                a++;
            if (a == words[i + 1].size() && a != words[i].size())
                return false;
            if (a != words[i].size() && a != words[i + 1].size() && map[words[i][a] - 'a'] > map[words[i + 1][a] - 'a'])
                return false;
        }
        return true;
    }
};