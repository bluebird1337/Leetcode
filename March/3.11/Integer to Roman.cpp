//https://leetcode.com/problems/coin-change/

#include <iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        vector<int>value = { 1000, 900, 500,  400,  100,  90,  50,  40,   10,   9,    5,   4,    1 };
        vector<string>sym = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
        for (int i = 0; i < value.size(); i++) {
            while (num >= value[i]) {
                res.append(sym[i]);
                num -= value[i];
            }
        }
        return res;
    }
};

int main() {
    Solution a;
    a.intToRoman(5);
    return 0;
}
