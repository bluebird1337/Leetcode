//https://leetcode.com/problems/spiral-matrix/

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int nr = matrix.size(), nc = matrix[0].size();
        vector<int>res;
        vector<vector<int>>dir = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
        vector<int>nstep = { nc, nr - 1 };
        int currdir = 0;
        int x = 0, y = -1;
        while (nstep[currdir % 2]) {
            for (int i = 0; i < nstep[currdir % 2]; i++) {
                x += dir[currdir][0];
                y += dir[currdir][1];
                res.push_back(matrix[x][y]);
            }
            nstep[currdir % 2] --;
            currdir = (currdir + 1) % 4;
        }
        return res;
    }
};
