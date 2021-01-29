//https://leetcode.com/problems/3sum/

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& num) {
        int size = num.size();
        vector<vector<int>>res;
        if (size < 3) return res;

        sort(num.begin(), num.end());
        int start, end, two_sum;
        for (int i = 0; i < size - 2; i++) {
            start = i + 1, end = size - 1;
            while (start < end) {
                two_sum = num[start] + num[end];
                
                if (two_sum < -num[i]) {
                    start++;
                }
                else if ( two_sum > -num[i]){
                    end--;
                }
                else {
                    vector<int>tmp = { num[i], num[start] , num[end] };
                    res.push_back(tmp);
                    start++, end--;
                    //move start to next index that aren't dubplicate
                    while (start < end && num[start] == tmp[1]) {
                        start++;
                    }
                    //move end to next index that aren't dubplicate
                    while (start < end && num[end] == tmp[2]) {
                        end--;
                    }
                }
            }
            //move i  to next index that aren't dubplicate
            while (i < size - 2 && num[i] == num[i + 1])
                i++;
        }
        return res;
    }
};

int main() {
    Solution a;
    vector<int> num = { -4, -2, 1, -5, -4, -4, 4, -2, 0, 4, 0, -2, 3, 1, -5, 0 };
    a.threeSum(num);
    return 0;
}