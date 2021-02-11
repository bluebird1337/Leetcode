/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

Follow up: Could you implement a solution with a linear runtime complexity and without using extra memory?
*/


/*
XOR:
True XOR True = False
False XOR False = False
False XOR True = True
True XOR False = True
**/

int singleNumber(int* nums, int numsSize) {
	int ans = nums[0];
	for (int i = 1; i < numsSize; i++) {
		ans = ans ^ nums[i];
	}
	return ans;
}