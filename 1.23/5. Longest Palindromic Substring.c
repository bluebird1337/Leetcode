/*
https://leetcode.com/problems/longest-palindromic-substring/
Given a string s, return the longest palindromic substring in s.
*/
#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void update(int tmp, int* max, char** res, int start, int end, char* s) {
	if (tmp > (*max)) {// if tmp == max we neglect
		char* realoc = NULL;
		realoc = (char*)realloc(*res, sizeof(char) * (end - start + 2));
		if (realoc) {
			strncpy(realoc, s + start, end - start + 1);
			realoc[end - start + 1] = '\0';
			*res = realoc;
		}
		(*max) = tmp;
		return;
	}
	else
		return;
}

char* longestPalindrome(char* s) {
	int len = strlen(s), max = 0, tmp, i, j;
	if (len == 1) return s;
	int p;//pivot
	char* res = NULL;
	for (p = 0; p < len; p++) {
		tmp = 1;
		if (p == 0) {
			if (s[p] == s[p + 1]) {
				update(tmp + 1, &max, &res, p, p + 1, s);
				continue;
			}
			else {
				update(tmp, &max, &res, p, p, s);
				continue;
			}
		}
		else if (p == len - 1) {
			if (s[p] == s[p - 1]) {
				update(tmp + 1, &max, &res, p - 1, p, s);
				continue;
			}
		}
		else {
			i = p - 1, j = p + 1;
			while (i >= 0 && s[i] == s[p]) {
				tmp++, i--;
			}
			while (j < len && s[j] == s[p]) {
				tmp++, j++;
			}
			while (i >= 0 && p < len && s[i] == s[j]) {
				tmp += 2, i--, j++;
			}
			if (tmp == 1) {
				if (s[p] == s[p + 1]) {
					update(tmp + 1, &max, &res, p, p + 1, s);
				}
				continue;
			}
			else {
				update(tmp, &max, &res, i + 1, j - 1, s);
				continue;
			}
		}
	}
	return res;
}


int main() {
	char s[] = "aaaa";
	printf("%s", longestPalindrome(s));
	return 0;
}