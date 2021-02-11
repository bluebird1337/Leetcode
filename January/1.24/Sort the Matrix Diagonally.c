//https://leetcode.com/problems/sort-the-matrix-diagonally/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a, const void* b) {
	return (*(int*)a) - (*(int*)b);
}

int** diagonalSort(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes) {
	*returnSize = matSize;
	int m = matSize, n = matColSize[0];
	*returnColumnSizes = (int*)malloc(sizeof(int) * m);
	for (int i = 0; i < m; i++) {
		(*returnColumnSizes)[i] = *matColSize;
	}

	int list[105] = { 0 };//store diagonal 
	int i, j, tmpi, tmpj, index;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (i == 0 || j == 0) {
				index = 0;
				tmpi = i, tmpj = j;
				while (tmpi < m && tmpj < n) {
					list[index++] = mat[tmpi++][tmpj++];
				}
				qsort(list, index, sizeof(int), cmp);
				while (--tmpi >= i && --tmpj >= j) {
					mat[tmpi][tmpj] = list[--index];
				}
			}
		}
	}
	return mat;
}