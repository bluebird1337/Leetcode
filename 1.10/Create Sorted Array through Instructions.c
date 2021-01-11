/*

Given an integer array instructions, you are asked to create a sorted array from the elements in instructions. You start with an empty container nums. For each element from left to right in instructions, insert it into nums. The cost of each insertion is the minimum of the following:

The number of elements currently in nums that are strictly less than instructions[i].
The number of elements currently in nums that are strictly greater than instructions[i].
For example, if inserting element 3 into nums = [1,2,3,5], the cost of insertion is min(2, 1) (elements 1 and 2 are less than 3, element 5 is greater than 3) and nums will become [1,2,3,3,5].

Return the total cost to insert all elements from instructions into nums. Since the answer may be large, return it modulo 109 + 7

Constraints:

1 <= instructions.length <= 105
1 <= instructions[i] <= 105

*/
#pragma warning(disable:6011)
#include<stdio.h>
#include<stdlib.h>

#define MOD 1000000009
void insert(int** nums, int index, int val, int *size) {
	int i;
	if (*size == 0) {
		(*nums)[0] = val;
		(*size)++;
	}
	else {
		for (i = *size ; i > index; i--) {
			(*nums)[i] = (*nums)[i - 1];
		}
		(*nums)[i] = val;
		(*size)++;
	}
}

int createSortedArray(int* instructions, int instructionsSize) {
	int smaller = 0, greater = 0, cost = 0, i, j, tmp, numsSize;
	int* nums = NULL;
	nums = (int*)malloc(sizeof(int) * instructionsSize);
	nums[0] = instructions[0];
	numsSize = 1;

	for (i = 1; i < instructionsSize; i++) {
		j = 0;
		while (j<numsSize && instructions[i]>nums[j]) {
			j++;
		}
		if (j == numsSize) { //instruction[i] is the greatest element among entire nums array, cost = 0
			insert(&nums, j, instructions[i], &numsSize);
		}
		else if (nums[j] == instructions[i]) { //found
			tmp = j;
			while (nums[tmp] == instructions[i] && tmp < numsSize) {
				tmp++;
			}
			if (tmp == numsSize)
				greater = 0;
			else
				greater = numsSize - tmp;
			smaller = j;
			cost = (cost % MOD + (min(smaller, greater))%MOD ) % MOD;
			insert(&nums, j, instructions[i], &numsSize);
		}
		else{ // not found
			smaller = j;
			greater = numsSize - j;
			cost = (cost % MOD + (min(smaller, greater)) % MOD) % MOD;
			insert(&nums, j, instructions[i], &numsSize);
		}
	}

	return cost;
}

int main() {
	int instructions[] = { 1,5,6,2 };

	printf("%d", createSortedArray(instructions, 4));

	return 0;
}
