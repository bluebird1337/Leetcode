/*

https://leetcode.com/problems/longest-palindromic-substring/

Given a string s, return the longest palindromic substring in s.
Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters (lower-case and/or upper-case),
*/
#pragma warning(disable:4996)
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

void update(int tmp, int* max, char** res, int start, int end, char* s) {
	if (tmp > (*max)) {// if tmp == max we neglect
		if (*res) {
			char* realoc = NULL;
			realoc = (char*)realloc(*res, sizeof(char) * (end - start + 2));
			if (realoc) {
				strncpy(realoc, s + start, end - start + 1);
				realoc[end - start + 1] = '\0';
				*res = realoc;
			}
		}
		(*max) = tmp;
		return;
	}
	else
		return;
}

char* longestPalindrome(char* s) {
	int max = 0, len = strlen(s), tmp, i, j;
	char* res = (char*)malloc(sizeof(char));
	int p;//pivot
	for (p = 0; p < len; p++) {
		//initialize length of substring with pivot = p
		tmp = 1;
		if (p == 0 || p == len - 1) {
			if (len == 2) {
				if (p == 0 && s[p] == s[p + 1]) {
					tmp++;
					update(tmp, &max, &res, p, p + 1, s);
				}
			}
			else {
				update(tmp, &max, &res, p, p, s);
			}
			continue;
		}
		else {
			i = p - 1, j = p + 1;
			while (i >= 0 && j < len && (s[i] == s[j])) {
				tmp += 2;
				i--;
				j++;
			}
			if (tmp == 1) {
				if (s[p] == s[p + 1]) { // special case: "abbc"
					tmp++;
					update(tmp, &max, &res, p, p + 1, s);
				}
				if (s[p] == s[p - 1]) { //special case "bbc"
					tmp++;
					update(tmp, &max, &res, p - 1, p, s);
				}
				continue;
			}
			else {
				update(tmp, &max, &res, i + 1, j - 1, s);
			}
		}
	}
	return res;
}

