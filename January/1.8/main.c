#pragma warning(disable:4996)
#include<stdio.h>
#include <stdbool.h>
#include<stdlib.h>
#include<string.h>

#define SIZE 200000
struct hashing
{
	int key;
	int count;
	struct hashing* next;
}h[SIZE];

int fourSumCount(int* A, int ASize, int* B, int BSize, int* C, int CSize, int* D, int DSize);
int search(int num);
void addhash(int num);

int main() {

	int a[] = { -1, -1 }, b[] = { -1, 1 }, c[] = { -1, 1 }, d[] = { 1, -1 };
	printf("%d", fourSumCount(a, 2, b, 2, c, 2, d, 2));

	return 0;
}