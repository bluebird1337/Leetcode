// https://leetcode.com/problems/simplify-path/

#include <iostream>
#include <sstream>  
#include<string>
#include<vector>
using namespace std;


class Solution {
public:
    string simplifyPath(string path) {
        string res, tmp;
        vector<string>stack;
        stringstream ss(path);
        while (getline(ss, tmp, '/')) {
            if (tmp == "" || tmp == ".") continue;
            if (tmp == ".." && !stack.empty()) stack.pop_back();
            if (tmp!="..") stack.push_back(tmp);
        }
        for (auto st : stack) {
            res = res + "/" + st;
        }
        return res.empty() ? "/" : res;
    }
};

