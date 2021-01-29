//https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/

#include <iostream>
#include<string>
using namespace std;


class Solution {
public:
    string getSmallestString(int n, int k) {
        string res(n, 'a');
        int remain = n - 1;
        char c;
        for (; remain >= 0 ; remain--) {
            if (k == remain+1) {
                break;
            }
            if (k - remain >= 26) {
                c = 'z';
                res[remain] = c;
                k -= 26;
            }
            else {
                c = char((k - remain) + 'a' - 1);
                res[remain] = c;
                k -= (k - remain);
            }
        }
        return res;
    }
};
