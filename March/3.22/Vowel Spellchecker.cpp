// https://leetcode.com/problems/vowel-spellchecker/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string to_lower(string s) {
        string res;
        for (auto c : s) {
            auto tmp = c < 91 ? c + 32 : c;
            res.push_back(tmp);
        }
        return res;
    }
    string to_vowel(string s) {
        string res;
        for (auto c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') 
                c = '#';
            res.push_back(c);
        }
        return res;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        int size = queries.size();
        set<string>words(wordlist.begin(), wordlist.end());
        map<string, string>low, vow;
        for (string str : wordlist) {
            string l = to_lower(str), v = to_vowel(l);
            low.insert({ l, str });
            vow.insert({ v, str });
        }
        for (int i = 0; i < size; i++) {
            string l = to_lower(queries[i]), v = to_vowel(l);
            if (words.find(queries[i]) != words.end())
                continue;
            else if (low.find(l) != low.end())
                queries[i] = low[l];
            else if (vow.find(v) != vow.end())
                queries[i] = vow[v];
            else
                queries[i] = "";
        }
        return queries;
    }
};

