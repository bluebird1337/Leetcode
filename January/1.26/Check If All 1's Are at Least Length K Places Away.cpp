//Check If All 1's Are at Least Length K Places Away

#include <iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        vector<int>pos;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1)
                pos.push_back(i);
        }
        if (pos.size() == 0)
            return true;

        for (int i = 0; i < pos.size() - 1; i++) {
            if (pos[i + 1] - pos[i] < (k + 1))
                return false;
        }
        return true;
    }
};
