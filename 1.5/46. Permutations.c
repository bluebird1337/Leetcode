#pragma warning(disable:6011)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */


#include<stdio.h>

void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void f(int k, int numsSize, int** buffer, int*** result, int* rIdx) {
	if (k == numsSize) {
		memcpy( (*result)[(*rIdx)++], *buffer, numsSize * sizeof(int) );
		for (int i = 0; i < k; i++)
			printf("%d", (*buffer)[i]);
		printf("\n");
	}
	for (int i = k; i < numsSize; i++) {
		swap( &(*buffer)[i], &(*buffer)[k]);
		f(k + 1, numsSize, buffer, result, rIdx);
		swap( &(*buffer)[i], &(*buffer)[k]);
	}
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
	int** result = NULL;
	int rIdx = 0;
	int count = 1;
	for (int i = 1; i <= numsSize; i++)
		count *= i;
	*returnSize = count;
	result = (int**)malloc(sizeof(int*) * count);
	(*returnColumnSizes) = (int*)malloc(sizeof(int) * count);
	for (int i = 0; i < count; i++) {
		(*returnColumnSizes)[i] = numsSize;
		result[i] = (int*)malloc(sizeof(int) * numsSize);
	}

	f(0, numsSize, &nums, &result, &rIdx);

	return result;
}

