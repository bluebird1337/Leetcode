// https://leetcode.com/problems/distribute-candies/

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        sort(candyType.begin(), candyType.end());
        int types = 1;
        int currtype = candyType[0];
        for (int i = 1; i < n; i++) {
            if (candyType[i] != currtype)
                types++;
            currtype = candyType[i];
        }
        return types > n / 2 ? n / 2 : types;
    }
};
