#include<stdio.h>
#include <stdbool.h>

int search(int tar, int* arr, int arrSize) {
	int ans = -1;
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] == tar) {
			ans = i;
			break;
		}
	}
	return ans;
}

bool canFormArray(int* arr, int arrSize, int** pieces, int piecesSize, int* piecesColSize) {
	int tmp, index;
	for (int i = 0; i < piecesSize; i++) {
		tmp = pieces[i][0];
		index = search(tmp, arr, arrSize);
		if (index == -1)
			return false;
		else {
			for (int j = 0; j < piecesColSize[i]; j++) {
				if ((index + j) >= arrSize || arr[index + j] != pieces[i][j])
					return false;
			}
		}
	}
	return true;
}