/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
https://leetcode.com/problems/kth-largest-element-in-an-array/
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.

Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/

#include<stdlib.h>
int cmp(const void* a, const void* b) {
	return (*(int*)a) - (*(int*)b);
}

int findKthLargest(int* nums, int numsSize, int k) {
	qsort(nums, numsSize, sizeof(int), cmp);
	return nums[numsSize - k];
}