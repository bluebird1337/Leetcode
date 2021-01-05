#include<stdio.h>


void swap(int* a, int* b);
void f(int k, int numsSize, int** buffer, int*** result, int* rIdx);
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);

int main() {
	int** result;
	int nums[3] = { 1, 2, 3 };
	int returnSz;
	int* returnColSz;
	result = permute(nums, 3, &returnSz, &returnColSz);

	

	return 0;
}