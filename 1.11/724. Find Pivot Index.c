/*

https://leetcode.com/problems/find-pivot-index/

Given an array of integers nums, write a method that returns the "pivot" index of this array.

We define the pivot index as the index where the sum of all the numbers to the left of the index is equal to the sum of all the numbers to the right of the index.

If no such index exists, we should return -1. If there are multiple pivot indexes, you should return the left-most pivot index.
Constraints:

The length of nums will be in the range [0, 10000].
Each element nums[i] will be an integer in the range [-1000, 1000].
*/
#include<stdio.h>
#include<stdlib.h>

int pivotIndex(int* nums, int numsSize) {
    if (numsSize == 0)
        return -1;

    int* prefix;
    prefix = (int*)malloc(sizeof(int) * numsSize);
    prefix[0] = nums[0];
    for (int i = 1; i < numsSize ; i++)
        prefix[i] = prefix[i - 1] + nums[i];

    int res = -1;
    for (int i = 0; i < numsSize ; i++) {
        if (i == 0) {
            if (prefix[numsSize - 1] - prefix[0] == 0) 
                return 0;
        }
        else if (i == numsSize - 1) {
            if (prefix[numsSize - 2] == 0)
                return numsSize - 1;
        }
        else {
            if ((prefix[numsSize - 1] - prefix[i]) == prefix[i - 1]) {
                res = i;
                break;
            }
        }
    }
    return res;
}

int main() {
    int nums[] = {-1, 1, -1, 1, 3 };
    printf("%d ", pivotIndex(nums, 5));
    return 0;
}