//https://leetcode.com/problems/n-queens/
#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>>res;
    unordered_map<int, int>diagonal, diagonal2, vertical;
    int isValid(int row, int column) {
        unordered_map<int, int>::iterator it;
        //check diagonal '/'
        it = diagonal.find(row + column);
        if (it != diagonal.end())
            return 0;
        //check diagonal '\'
        it = diagonal2.find(column - row);
        if (it != diagonal2.end())
            return 0;
        //check vertical
        it = vertical.find(column);
        if (it != vertical.end())
            return 0;
        //All valid
        return 1;
    }
    void add_to_list(vector<vector<int>>board) {
        vector<string>tmp;
        for (int i = 0; i < board.size();i++) {
            string line = "";
            for (int j = 0; j < board.size(); j++) {
                if (board[i][j] == 1)
                    line.push_back('Q');
                else
                    line.push_back('.');
            }
            tmp.push_back(line);
        }
        res.push_back(tmp);
    }
    void PlaceQueen(vector<vector<int>>board, int row){
        if (row == board.size()) {
            add_to_list(board);
            return;
        }
        for (int j = 0; j < board.size(); j++) {
            if (isValid(row, j)) {
                diagonal[row + j] = 1;
                diagonal2[j - row] = 1;
                vertical[j] = 1;
                PlaceQueen(board, row + 1);
                unordered_map<int, int>::iterator it;
                it = diagonal.find(row + j);
                diagonal.erase(it);
                it = diagonal2.find(j - row);
                diagonal2.erase(it);
                it = vertical.find(j);
                vertical.erase(it);
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>>board;
        for (int i = 0; i < n; i++) {
            vector<int>tmp;
            for (int j = 0; j < n; j++) {
                tmp.push_back(0);
            }
            board.push_back(tmp);
        }
        PlaceQueen(board, 0);
        return res;
    }
};

int main() {
    Solution a;
    a.solveNQueens(4);
    return 0;
}