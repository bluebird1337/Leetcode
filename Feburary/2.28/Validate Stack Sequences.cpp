// https://leetcode.com/problems/validate-stack-sequences/

#include <iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0, j = 0, push_s = pushed.size(), pop_s = popped.size();
        stack<int> st;
        while (j < pop_s) {
            if (i == push_s) { //already push all element in vector pushed 
                int tmp = st.top();
                if (tmp == popped[j]) {
                    j++;
                    st.pop();
                }
                else 
                    break;
            }
            else if (!st.empty() && st.top() == popped[j]) { 
                st.pop();
                j++;
            }
            else { // st is empty or st.top != popped[j] 
                while (i < push_s && pushed[i] != popped[j]) {
                    st.push(pushed[i]);
                    i++;
                }
                if (i == push_s) 
                    break;
                i++, j++;
            }
        }
        return j == pop_s;
    }
};

int main() {
    Solution s;
    vector<int>a = { 1, 2, 3, 4, 5, 6, 7}, b = {1, 2, 5, 3, 6, 7, 4 };
    if (s.validateStackSequences(a, b))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    return 0;
}

