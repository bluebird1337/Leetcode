//https://leetcode.com/problems/rotate-image/

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; i++) {
            for (int j = i; j < n - 1 - i; j++) {
                int a = matrix[i][j];
                int b = matrix[j][n - 1 - i];
                int c = matrix[n - 1 - i][n - 1 - j];
                int d = matrix[n - 1 - j][i];
                matrix[i][j] = d;
                matrix[j][n - 1 - i] = a;
                matrix[n - 1 - i][n - 1 - j] = b;
                matrix[n - 1 - j][i] = c;
                display(matrix);
            }
        }
        return;
    }
};

int main() {
    vector<vector<int>>matrix = { {5, 1, 9, 11} ,{2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16} };
    Solution a;
    a.rotate(matrix);
    return 0;
}