/*

https://leetcode.com/problems/subarray-sum-equals-k/

Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.

Constraints:
1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107
*/
#include<stdio.h>
#include<stdlib.h>
#define SIZE 10000

void add(int data);
int search(int data);
struct node{
	int key;
	int count;
	struct node* next;
}Hash[SIZE];

int subarraySum(int* nums, int numsSize, int k) {
	int res = 0, sum = 0, i;
	//initialize
	for (i = 0; i < SIZE; i++) {
		Hash[i].key = 0;
		Hash[i].count = 0;
		Hash[i].next = NULL;
	}
	add(0);
	//start add/search
	for (i = 0; i < numsSize; i++) {
		sum += nums[i];
		res += search(sum - k);
		add(sum);
	}
	return res;
}

void add(int data) {
	int tmp = abs(data % SIZE);
	if (Hash[tmp].count == 0) {
		Hash[tmp].key = data;
		Hash[tmp].count = 1;
		Hash[tmp].next = NULL;
	}
	else if (Hash[tmp].count != 0 && Hash[tmp].key == data)
		Hash[tmp].count++;
	else {
		struct node* p = &Hash[tmp];
		while (p->key != data && p->next != NULL)
			p = p->next;
		if (p->key == data)
			p->count++;
		else {
			p->next = (struct node*)malloc(sizeof(struct node));
			p = p->next;
			p->key = data;
			p->count = 1;
			p->next = NULL;
		}
	}
}

int search(int data) {
	int tmp = abs(data % SIZE);
	if (Hash[tmp].count == 0)
		return 0;
	else if (Hash[tmp].count != 0 && Hash[tmp].key == data)
		return Hash[tmp].count;
	else {
		struct node* p = &Hash[tmp];
		while (p->key != data && p->next != NULL)
			p = p->next;
		if (p->key == data)
			return p->count;
		else
			return 0;
	}
}

