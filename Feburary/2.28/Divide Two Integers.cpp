// https://leetcode.com/problems/divide-two-integers/

#include <iostream>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == -2147483648 && divisor == -1)
            return INT_MAX;
        else
            return int(dividend / divisor);
    }
};

