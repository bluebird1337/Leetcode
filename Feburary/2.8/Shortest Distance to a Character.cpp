// https://leetcode.com/problems/shortest-distance-to-a-character/

#include <iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int size = s.length();
        vector<int>res(size, -1), zerovec;
        for (int i = 0; i < size; i++) {
            if (s[i] == c) {
                res[i] = 0;
                zerovec.push_back(i);
            }
        }
        int numofzero = zerovec.size();
        for (int i = 0; i < numofzero; i++) {
            int posofzero = zerovec[i];
            //Toward left
            int iter = posofzero - 1, dist = 1;
            while (iter >= 0 && (res[iter] == -1 || res[iter] > dist) ) {
                res[iter] = dist;
                dist++;
                iter--;
            }
            //Toward right
            iter = posofzero + 1, dist = 1;
            while (iter <size && (res[iter] == -1 || res[iter] > dist)) {
                res[iter] = dist;
                dist++;
                iter++;
            }
        }
        return res;
    }
};

