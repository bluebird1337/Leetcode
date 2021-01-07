/*
https://leetcode.com/explore/challenge/card/january-leetcoding-challenge-2021/579/week-1-january-1st-january-7th/3595/

Given a string s, find the length of the longest substring without repeating characters.

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/
#pragma warning(disable:6011)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int lengthOfLongestSubstring(char* s) {
	int len = strlen(s);
	if (len == 0)
		return 0;

	int* ret;
	ret = (int*)malloc(sizeof(int) * (len));
	char ASC[128];

	int i, j;
	for (i = 0; i < len; i++) {
		memset(ASC, '0', 128);

		int count = 0;
		j = i;

		while (ASC[(int)s[j]] == '0'&& s[j]!='\0' ) {
			ASC[(int)s[j]] = '1';
			j++;
			count++;
		}
		ret[i] = count;
	}
	int max = ret[0];
	for (i = 1; i < len; i++) {
		if (ret[i] > max)
			max = ret[i];
	}

	return max;
}

int lengthOfLongestSubstring2(char* s) {
	int longestLength = 0, i = 0;
	int indexMap[128];
	//初始indexMap,來判斷是否已經有相同的char在indexMap中
	//int indexMap[128] = {[0 ... 1023] = -1};
	for (int i = 0; i < 128; i++) {
		indexMap[i] = -1;
	}
	printf("%d", i);
	for (int j = 0; s[j] != '\0'; j++) {
		printf("%c", s[j]);
		//看是否已經有相同的char在indexMap中,來藉此移動i的位置
		if (indexMap[s[j]] != -1) {
			i = indexMap[s[j]] > i ? indexMap[s[j]] : i;
		}
		longestLength = longestLength > j - i + 1 ? longestLength : j - i + 1;
		indexMap[s[j]] = j + 1;
	}
	return longestLength;
}