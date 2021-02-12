//https://leetcode.com/problems/set-matrix-zeroes/

#include <iostream>
#include<vector>
#include <set>
#include<algorithm>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int>column, row;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0;  j < n; j++) {
                if (matrix[i][j] == 0) {
                    row.insert(i);
                    column.insert(j);
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (row.find(i) != row.end() || column.find(j) != column.end())
                    matrix[i][j] = 0;
            }
        }
    }
};


