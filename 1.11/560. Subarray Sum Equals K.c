/*

https://leetcode.com/problems/subarray-sum-equals-k/

Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.
Constraints:

1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 10
*/
#include<stdio.h>
#include<stdlib.h>

int subarraySum(int* nums, int numsSize, int k) {
    int* prefix;
    prefix = (int*)malloc(sizeof(int) * numsSize + 1);
    int res = 0;
    //construct prefix
    prefix[0] = 0;
    for (int i = 1; i <= numsSize; i++)
        prefix[i] = prefix[i - 1] + nums[i - 1];

    //count the result
    for (int i = 0; i <= numsSize; i++) {
        for (int j = i + 1; j <= numsSize; j++) {
            if (prefix[j] - prefix[i] == k)
                res++;
        }
    }
    return res;
}