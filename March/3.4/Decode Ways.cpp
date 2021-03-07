//https://leetcode.com/problems/decode-ways/

#include <iostream>
#include <string> 
using namespace std;

class Solution {
public:
    void perm(int index, string s, int& res) {
        if (index == s.size()) {
            res++;
            return;
        }
        if (s[index] == '0')
            return;
        perm(index + 1, s, res);
        //Merge with next element
        if (index != s.size() - 1) { // last element don't have next element
            if (s[index] == '1')
                perm(index + 2, s, res);
            else if (s[index] == '2') {
                int tmp = int(s[index + 1]) - 48;
                if (tmp <= 6) {
                    perm(index + 2, s, res);
                }
            }
            else
                return;
        }
    }
    int numDecodings(string s) {
        int res = 0;
        perm(0, s, res);
        return res;
    }
};

