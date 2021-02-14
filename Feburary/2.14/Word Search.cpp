//https://leetcode.com/problems/word-search/

#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int m, n;
    bool DFS(int x, int y, int index, string word, vector<vector<char>> board, vector<vector<int>>&visited) {
        if (index == word.length())
            return true;
        vector<vector<int>>dir = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
        for (int i = 0; i < 4; i++) {
            int next_x = x + dir[i][0];
            int next_y = y + dir[i][1];
            if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n && board[next_x][next_y] == word[index] && visited[next_x][next_y] == 0) {
                visited[next_x][next_y] = 1;
                if (DFS(next_x, next_y, index + 1, word, board, visited))
                    return true;
                visited[next_x][next_y] = 0;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        this->m = board.size();
        this->n = board[0].size();
        vector<vector<int>>visited(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    visited[i][j] = 1;
                    if (DFS(i, j, 1, word, board, visited))
                        return true;
                    visited[i][j] = 0;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution a;
    vector<vector<char>> board = { {'C', 'A', 'A'},{'A', 'A', 'A'},{'B', 'C', 'D'} };
    string word = "AAB";
    a.exist(board, word);
    return 0;
}
