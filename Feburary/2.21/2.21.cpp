// https://leetcode.com/problems/broken-calculator/

#include <iostream>
#include<queue>
using namespace std;

class Solution {
public:
    int brokenCalc(int X, int Y) {
        int res = 0;
        while (X < Y) {
            res += 1 + (Y % 2);
            if (Y % 2) Y += 2;
            Y /= 2;
        }
        return res + (X-Y);
    }
};

