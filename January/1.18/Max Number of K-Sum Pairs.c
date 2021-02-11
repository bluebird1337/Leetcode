/*
https://leetcode.com/problems/max-number-of-k-sum-pairs/

You are given an integer array nums and an integer k.

In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.

Return the maximum number of operations you can perform on the array.
Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= k <= 109
*/
#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a, const void* b) {
	return ((*(const int*)a) - (*(const int*)b));
}
int maxOperations(int* nums, int numsSize, int k) {
	qsort(nums, numsSize, sizeof(int), cmp);

	int i = 0, j = numsSize - 1, res = 0;
	while (i < j) {
		int tmp = nums[i] + nums[j];
		if (tmp > k)
			j--;
		else if (tmp < k)
			i++;
		else {
			res++;
			i++, j--;
		}
	}
	return res;
}