#include<iostream>
#include <vector>
#include <sstream>
#include<string>
#include<math.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int i=0 ; i<T ; i++){ 
        int L, R;
        cin >> L >> R;
        //Create Board
        vector<int>row(L, 0);
        vector<vector<int>>board(L, row);
        stringstream ss;
        for (int i = 0; i < R; i++) { //Each row
            int ins_row;
            string s;
            getline(cin, s);
            ss >> ins_row;
            int num;
            int index = 0;
            while (ss >> num) {
                board[ins_row][index] = num;
                index++;
            }
        }
        // output the number
        int res = 0;
        for (int i = 0; i < L; i++) { // row
            int tmp = 0;
            for (int j = L-1; j >=0 ; j--) { // column
                tmp += board[j][i] * (pow(10, (L - 1 - j)));
            }
            res += tmp;
        }
        cout << res << endl;
    }
    return 0;
}