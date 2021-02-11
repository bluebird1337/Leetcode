/*
https://leetcode.com/problems/4sum-ii/

Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.
*/
#include<stdio.h>

#define SIZE 200000
struct hashing
{
	int key;
	int count;
	struct hashing* next;
}h[SIZE];

void addhash(int num) {
	int tmp = abs((num) % SIZE);

	if (h[tmp].count == 0) {
		h[tmp].key = num;
		h[tmp].count++;
	}
	else {
		if (h[tmp].key == num) {
			h[tmp].count++;
		}
		else {
			struct hashing* p = &h[tmp];
			while (p->key != num && p->next) {
				p = p->next;
			}
			if (p->key == num) {
				p->count++;
			}
			else {
				p->next = (struct hashing*)malloc(sizeof(struct hashing));
				p = p->next;
				p->key = num;
				p->count = 1;
				p->next = NULL;
			}
		}
	}
	return;
}

int search(int num) {
	int tmp = abs((num) % SIZE);
	if (h[tmp].count == 0)
		return 0;
	else {
		if (h[tmp].key == num) {
			return h[tmp].count;
		}
		else {
			struct hashing* p = &h[tmp];
			while (p->key != num && p->next) {
				p = p->next;
			}
			if (p->key == num) 
				return p->count;
			else {
				return 0;
			}
		}
	}
	return 0;
}


int fourSumCount(int* A, int ASize, int* B, int BSize, int* C, int CSize, int* D, int DSize) {
	int i, j ,res = 0;
	for (i = 0; i < SIZE; i++) {
		h[i].count = 0;
		h[i].key = 0;
		h[i].next = NULL;
	}

	for (i = 0; i < ASize; i++) {
		for (j = 0; j < BSize; j++)
			addhash(A[i] + B[j]);
	}
	
	for (i = 0; i < CSize; i++) {
		for (j = 0; j < DSize; j++) {
			res += search(- (C[i] + D[j]) );
		}
	}
	return res;
}