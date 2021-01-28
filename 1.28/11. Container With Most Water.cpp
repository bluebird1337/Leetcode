//https://leetcode.com/problems/container-with-most-water/

#include <iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int l = height[i] < height[j] ? height[i] : height[j];
        int res = (j - i) * l;
        while (i < j) {
            //find next l
            if (l == height[i]) {
                while (l >= height[i] && i<j) { 
                    i++; 
                }
                if (i == j) break;
                l = height[i] < height[j] ? height[i] : height[j];
            }
            else if (l == height[j]) {
                while (l >= height[j] && i<j) { 
                    j--; 
                }
                if (i == j) break;
                l = height[j] < height[i] ? height[j] : height[i];
            }
            res = res < (j - i)* l ? (j - i) * l : res;
        }
        return res;
    }
};

int main() {
    Solution a;
    vector<int>height = { 1,8,6,2,5,4,8,3,7 };
    a.maxArea(height);
    return 0;
}