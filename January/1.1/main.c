#pragma warning (disable:4996)
#pragma warning (disable:6031)
#pragma warning (disable:6011)
#include<stdio.h>
#include <stdbool.h>
#include<stdlib.h>


int search(int tar, int* arr, int arrSize);
bool canFormArray(int* arr, int arrSize, int** pieces, int piecesSize, int* piecesColSize);

int main() {
	
	int* arr, * piecesColSize;
	int arrsize;
	printf("Enter arrSize:\n");
	scanf("%d", &arrsize);
	arr = (int*)malloc(sizeof(int) * arrsize);
	printf("Enter %d elements of arr:\n", arrsize);
	for (int i = 0; i < arrsize; i++)
		scanf("%d", &arr[i]);

	int piecesSize;
	printf("Enter piecesSize:\n");
	scanf("%d", &piecesSize);
	piecesColSize = (int*)malloc(sizeof(int) * piecesSize);
	printf("Enter each size of Column:\n");
	for (int i = 0; i < piecesSize; i++)
		scanf("%d", &piecesColSize[i]);

	int** pieces;
	pieces = (int**)malloc(sizeof(int*) * piecesSize);
	for (int i = 0; i < piecesSize; i++) {
		pieces[i] = (int*)malloc(sizeof(int) * piecesColSize[i]);
	}
	for (int i = 0; i < piecesSize; i++) {
		for (int j = 0; j < piecesColSize[i]; j++) {
			printf("Enter [%d][%d] elements :\n", i, j);
			scanf("%d", &pieces[i][j]);
		}
	}


	if (canFormArray(arr, arrsize, pieces, piecesSize, piecesColSize) == false)
		printf("false");
	else
		printf("true");

	return 0;
}