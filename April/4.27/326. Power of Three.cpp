//https://leetcode.com/problems/power-of-three/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        int sum = 0;
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return sum % 3 == 0;
    }
};


int main() {
    Solution a;
    if (a.isPowerOfThree(27))
        cout << "True" << endl;
    return 0;
}