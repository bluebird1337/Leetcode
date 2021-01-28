//https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/

#include <iostream>
#include<string>
using namespace std;

//O(nlog(n))
class Solution {
public:
    int concatenatedBinary(int n) {
        long ans = 0, mod = 1e9 + 7;
        for (int i = 1; i <= n; ++i) {
            int len = 0;
            for (int j = i; j; j >>= 1, ++len);
            ans = ((ans << len) % mod + i) % mod;
        }
        return ans;
    }
};


/*TLE
#define MOD ((int)1e9+7)
class Solution {
public:
    int compute_len(int n) {
        int length = 0;
        while (n) {
            length++;
            n /= 2;
        }
        return length;
    }
    int concatenatedBinary(int n) {
        long long int res = 0, sum_len = 0;
        for (int i = n; i > 0; i--) {
            int x = i;
            for (int j = 1; j <= sum_len; j++) {
                x = (x << 1) % MOD;
            }
            res = ((res % MOD) + x ) %MOD;
            sum_len += compute_len(i);
        }
        return res;
    }
};

int main() {
    Solution a;
    a.concatenatedBinary(12);
    return 0;
}
*/