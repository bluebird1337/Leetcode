/*
https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
*/
#include<stdlib.h>
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
	int tmp , i;
	for (i = 0; i < numsSize; i++) {
		tmp = nums[i];
		tmp = tmp > 0 ? tmp : -tmp;
		if (nums[tmp - 1] > 0) nums[tmp - 1] *= -1;
	}
	int* arr = (int*)malloc(sizeof(int) * numsSize);
	int j = 0;
	for (i = 0; i < numsSize; i++) {
		if (nums[i] > 0) {
			arr[j++] = i + 1;
		}
	}
	*returnSize = j;
	return arr;
}