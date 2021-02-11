/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
*/

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int find_zero(int*nums, int index, int size) {
	if (index == size - 1)
		return -1;
	for (; index < size; index++) {
		if (nums[index] == 0)
			return index;
	}
	return -1;
}

void moveZeroes(int* nums, int numsSize) {
	int i, flag;
	flag = find_zero(nums, 0, numsSize);
	
	for (i = flag + 1; i < numsSize; i++) {
		if (flag == -1) {
			break;
		}
		if (nums[i] == 0)
			continue;
		else {
			swap(&nums[flag], &nums[i]);
			flag = find_zero(nums, flag + 1, numsSize);
		}
	}

}