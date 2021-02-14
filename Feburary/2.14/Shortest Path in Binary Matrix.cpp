// https://leetcode.com/problems/shortest-path-in-binary-matrix/

#include <iostream>
#include<vector>
#include <utility>
#include <queue>   
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        vector<vector<int>>dir = { {-1, -1}, {-1, 0}, {0, -1}, {1, -1}, {-1, 1}, {1, 0}, {0, 1}, {1, 1} };
        queue<pair<int, int>>my_queue;
        grid[0][0] = 1;
        my_queue.push(make_pair(0, 0));
        while (!my_queue.empty()) {
            pair<int, int>tmp = my_queue.front();
            if (tmp.first == n - 1 && tmp.second == n - 1)
                return grid[tmp.first][tmp.second];
            for (auto direction : dir) {
                int x = tmp.first + direction[0];
                int y = tmp.second + direction[1];
                if ( x>= 0 && x < n &&  y>= 0 && y < n && grid[x][y] == 0) {
                    grid[x][y] = grid[tmp.first][tmp.second] + 1;
                    my_queue.push(make_pair(x, y));
                }
            }
            my_queue.pop();
        }
        return -1;
    }
}; 


/*
class Solution {
public:
    int n;
    vector<vector<int>>dir = { {-1, -1}, {-1, 0}, {0, -1}, {1, -1}, {-1, 1}, {1, 0}, {0, 1}, {1, 1} };
    vector<vector<int>>grid;
    bool isValid(int i, int j, vector<vector<int>>visited) {
        if (i>=0 && j>=0 && i < n && j < n && grid[i][j] == 0 && visited[i][j] == 0)
            return true;
        return false;
    }
    void DFS(int i, int j, int&min_len, int len, vector<vector<int>>&visited) {
        if (i == n - 1 && j == n - 1) {
            if (min_len > len)
                min_len = len;
            return;
        }
        for (int d = 0; d < 8; d++) {
            if(isValid(i + dir[d][0], j + dir[d][1], visited)) {
                visited[i + dir[d][0]][j + dir[d][1]] = 1;
                DFS(i + dir[d][0], j + dir[d][1], min_len, len + 1, visited);
                visited[i + dir[d][0]][j + dir[d][1]] = 0;
            }
        }
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0] == 1)
            return -1;
        this->grid = grid;
        this->n = grid.size();
        vector<vector<int>>visited(n, vector<int>(n, 0));
        visited[0][0] = 1;
        int min_len = INT_MAX;
        DFS(0, 0, min_len, 1 , visited);
        return min_len == INT_MAX ? -1 : min_len;
    }
};
*/
