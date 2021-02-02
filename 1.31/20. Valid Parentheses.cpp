//https://leetcode.com/problems/valid-parentheses/

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char& c : s) {
            if (c == '(' || c == '[' || c == '{')
                st.push(c);
            else {
                if (c == ')') {
                    if (st.top() != '(')
                        return false;
                    st.pop();
                }
                if (c == ']') {
                    if (st.top() != '[')
                        return false;
                    st.pop();
                }
                else {
                    cout<<(st.top());
                    if (st.top() != '{')
                        return false;
                    st.pop();
                }
            }
        }
        if (!st.empty())
            return false;
        return true;
    }
};
