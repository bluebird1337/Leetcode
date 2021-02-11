/*
Given an integer n, return the number of strings of length n that consist only of vowels (a, e, i, o, u) and are lexicographically sorted.

A string s is lexicographically sorted if for all valid i, s[i] is the same as or comes before s[i+1] in the alphabet.
Constraints:

1 <= n <= 50
*/
#include<stdio.h>

void DFS(int vowel_Idx, int index, int n, int* res ){
	if (index == n) {
		(*res) ++;
		return;
	}
	for (int i = vowel_Idx ; i < 5; i++) {
		DFS(i, index + 1, n, res);
	}
}

int countVowelStrings(int n) {
	int res = 0;
	DFS(0, 0, n, &res);
	return res;
}
