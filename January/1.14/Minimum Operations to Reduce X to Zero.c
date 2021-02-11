/*
You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.

Return the minimum number of operations to reduce x to exactly 0 if it's possible, otherwise, return -1.
Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 104
1 <= x <= 109
*/

#define max(a, b) ((a)>(b)?(a):(b))
int minOperations(int* nums, int numsSize, int x) {
	int target = -x;
	for (int i = 0; i < numsSize; i++) // target  = sum -x;
		target += nums[i];

	if (target == 0) // all element is positive
		return numsSize;
	if (target < 0) // sum < x
		return -1;

	//find the longest subarray that total value equals to target
	int start, end, curr, res = -1;
	start = curr = 0;
	for (end = 0; end < numsSize; end++) {
		curr += nums[end];
		while (curr > target || curr == target) {
			if (curr == target)
				res = max(res, end - start + 1);
			curr -= nums[start++];
		}
	}
	return res == -1 ? -1 : numsSize - res;
}

