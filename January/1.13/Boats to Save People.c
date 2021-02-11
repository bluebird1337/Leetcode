/*

https://leetcode.com/problems/boats-to-save-people/

The i-th person has weight people[i], and each boat can carry a maximum weight of limit.

Each boat carries at most 2 people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.  (It is guaranteed each person can be carried by a boat.)
Note:

1 <= people.length <= 50000
1 <= people[i] <= limit <= 30000
*/
#include <stdio.h>
#include <stdlib.h>

int cmp(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}


int numRescueBoats(int* people, int peopleSize, int limit) {
	qsort(people, peopleSize, sizeof(int), cmp);
	int i = 0, j = peopleSize - 1, res = 0;
	while (i < j) {
		if (people[i] + people[j] < limit || people[i] + people[j] == limit) {
			i++, j--, res++;
		}
		else {
			j--;
			res++;
		}
	}
	if (i == j) res++;
	return res;
}



int main() {
	int people[] = { 3,5,3,4 };
	printf("%d", numRescueBoats(people, 4, 5));

	return 0;
}
