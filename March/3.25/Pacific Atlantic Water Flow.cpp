//

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>>res;
    vector<vector<int>> visited;
    void DFS(int i, int j, vector<vector<int>> matrix, int preval, int pre) {
        if (i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size() || (visited[i][j] & pre) == pre || matrix[i][j] < preval)
            return;
        visited[i][j] |= pre;
        if (visited[i][j] == 3) {
            vector<int>tmp;
            tmp.push_back(i), tmp.push_back(j);
            res.push_back(tmp);
        }
        DFS(i + 1, j, matrix, matrix[i][j], visited[i][j]);
        DFS(i, j + 1, matrix, matrix[i][j], visited[i][j]);
        DFS(i - 1, j, matrix, matrix[i][j], visited[i][j]);
        DFS(i, j - 1, matrix, matrix[i][j], visited[i][j]);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty()) return res;
        int m = matrix.size(), n = matrix[0].size();
        visited.resize(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            DFS(i, 0, matrix, INT_MIN, 1);
            DFS(i, n-1, matrix, INT_MIN, 2);
        }
        for (int i = 0; i < n; i++) {
            DFS(0, i, matrix, INT_MIN, 1);
            DFS(m-1, i, matrix, INT_MIN, 2);
        }
        return res;
    }
};
