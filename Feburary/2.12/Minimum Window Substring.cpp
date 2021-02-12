//https://leetcode.com/problems/minimum-window-substring/

#include <iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s == "" || t == "")
            return "";
        string res;
        int left =0, count = 0, min_len = INT_MAX, right = 0;
        vector<int>ASCII(128, 0);
        //mark all letters inside t
        for (auto c : t) {
            ASCII[c]++;
        }
        //use two pointer loop through entire s
        for (; right < s.size(); right++) {
            if (--ASCII[s[right]] >= 0)
                count++;
            while (count == t.size()) { //found one solution
                if (min_len > right - left + 1) {
                    res = s.substr(left, right - left + 1);
                    min_len = right - left + 1;
                }
                //reduce the current length as much as possible
                if (++ASCII[s[left]] > 0) 
                    count--;
                left++;
            }
        }
        return res;
    }
};

int main() {
    Solution a;
    string t = "abcdAFDXES", s = "a";
    vector<int>ASCII(128, 0);
    //mark all letters inside t
    for (auto c:t) {
        ASCII[c]++;
    }

    //a.minWindow(s, t);
    return 0;
}