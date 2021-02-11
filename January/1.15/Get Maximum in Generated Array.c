/*
* 
* https://leetcode.com/problems/get-maximum-in-generated-array/
You are given an integer n. An array nums of length n + 1 is generated in the following way:

nums[0] = 0
nums[1] = 1
nums[2 * i] = nums[i] when 2 <= 2 * i <= n
nums[2 * i + 1] = nums[i] + nums[i + 1] when 2 <= 2 * i + 1 <= n
Return the maximum integer in the array nums​​​.
Constraints:

0 <= n <= 100
*/
#include<stdio.h>
#include<stdlib.h>
int getMaximumGenerated(int n) {
    int data[105];
    data[0] = 0;
    for (int i = 1; i <= n; i++) {
        if (i == 1)
            data[i] = 1;
        else {
            if (i % 2 == 0)
                data[i] = data[i / 2];
            else
                data[i] = data[i / 2] + data[i / 2 + 1];
        }
    }
    int max = data[0];
    for (int i = 1; i <= n; i++) {
        if (data[i] > max)
            max = data[i];
    }
    return max;
}

