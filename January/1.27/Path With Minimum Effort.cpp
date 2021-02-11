//https://leetcode.com/problems/path-with-minimum-effort/
#include <iostream>
#include<vector>
#include<cmath>
using namespace std;


class Solution {
public:
    bool check(int i, int j, int k, int m, int n, vector<vector<int>>& visited, vector<vector<int>>height) {
        if (i == m - 1 && j == n - 1) return true;

        visited[i][j] = 1;
        bool op = false;
        //Go up
        if (op == false && i > 0 && abs(height[i - 1][j] - height[i][j]) <= k && visited[i - 1][j] == 0) {
            op = op || check(i - 1, j, k, m, n, visited, height);
        }
        //Go down
        if (op == false && i < m-1 && abs(height[i+1][j] - height[i][j]) <= k && visited[i + 1][j] == 0) {
            op = op || check(i + 1, j, k, m, n, visited, height);
        }
        //Go left
        if (op == false && j > 0 && abs(height[i][j-1] - height[i][j]) <= k && visited[i][j-1] == 0) {
            op = op || check(i, j-1, k, m, n, visited, height);
        }
        //Go right
        if (op == false && j < n-1 && abs(height[i][j+1] - height[i][j]) <= k && visited[i][j+1] == 0) {
            op = op || check(i, j+1, k, m, n, visited, height);
        }
        return op;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int ans = INT_MAX, m = heights.size(), n = heights[0].size(), s = 0, e = (int)1e6, k;
        while (s <= e) {
            k = s + (e - s) / 2;
            vector<vector<int>>visited(100, vector<int>(100, 0));
            if (check(0, 0, k, m, n, visited, heights)) {
                ans = k;
                e = k - 1;
            }
            else{
                s = k + 1;
            }
        }
        return ans;
    }
};




/*TLE Brute force
class Solution {
public:
    int isValid(int x, int y, vector<vector<int>> visited, int row, int column) {
        if (x < 0 || x >= row)
            return 0;
        if (y < 0 || y >= column)
            return 0;
        if (visited[x][y] == 1)
            return 0;
        return 1;
    }

    void DFS(int x, int y, vector<vector<int>>heights, vector<vector<int>>& visited, int& res, int Maxeffort) {
        int row = heights.size(), column = heights[0].size();
        if (x == row - 1 && y == column - 1) {
            res = res > Maxeffort ? Maxeffort : res;
            return;
        }
        int diff; //abs betwenn current & next step
        int OriginalEffort = Maxeffort;
        //Go up
        if (isValid(x - 1, y, visited, row, column)) {
            visited[x - 1][y] = 1;
            diff = abs(heights[x - 1][y]-heights[x][y]);
            Maxeffort = diff > Maxeffort ? diff : Maxeffort;
            DFS(x - 1, y, heights, visited, res, Maxeffort);
            visited[x - 1][y] = 0;
            Maxeffort = OriginalEffort;
        }
        //Go down
        if (isValid(x + 1, y, visited, row, column)) {
            visited[x + 1][y] = 1;
            diff = abs(heights[x + 1][y] - heights[x][y]);
            Maxeffort = diff > Maxeffort ? diff : Maxeffort;
            DFS(x + 1, y, heights, visited, res, Maxeffort);
            visited[x + 1][y] = 0;
            Maxeffort = OriginalEffort;
        }
        //Go left
        if (isValid(x , y-1, visited, row, column)) {
            visited[x ][y-1] = 1;
            diff = abs(heights[x][y-1] - heights[x][y]);
            Maxeffort = diff > Maxeffort ? diff : Maxeffort;
            DFS(x, y-1, heights, visited, res, Maxeffort);
            visited[x][y-1] = 0;
            Maxeffort = OriginalEffort;
        }
        //Go right
        if (isValid(x, y+1, visited, row, column)) {
            visited[x][y+1] = 1;
            diff = abs(heights[x][y+1] - heights[x][y]);
            Maxeffort = diff > Maxeffort ? diff : Maxeffort;
            DFS(x, y+1, heights, visited, res, Maxeffort);
            visited[x][y+1] = 0;
            Maxeffort = OriginalEffort;
        }
        return;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int res = INT_MAX;
        int row = heights.size(), column = heights[0].size();
        vector<vector<int>>visited;
        for (int i = 0; i < row; i++) {
            vector<int>temp;
            for (int j = 0; j < column; j++)
                temp.push_back(0);
            visited.push_back(temp);
        }
        visited[0][0] = 1;
        DFS(0, 0, heights, visited, res, 0);
        return res;
    }
};
*/