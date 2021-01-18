/*https://leetcode.com/problems/word-break/
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

Note:

The same word in the dictionary may be reused multiple times in the segmentation.
You may assume the dictionary does not contain duplicate words.
*/
#pragma warning(disable:4996)
#pragma warning(disable:6011)
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


bool wordBreak(char* s, char** wordDict, int wordDictSize) {
	int len = strlen(s) + 1;
	bool* check = (bool*)calloc(len + 1, sizeof(bool));
	check[0] = true;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < wordDictSize; j++) {
			if (check[i]) {
				int wordlen = strlen(wordDict[j]);
				char* tmp = (char*)malloc(sizeof(char) * (wordlen + 1));
				strncpy(tmp, s + i, wordlen);
				tmp[wordlen] = '\0';
				
				if (strcmp(tmp, wordDict[j]) == 0)
					check[i + wordlen] = true;
			}
		}
	}
	return check[len - 1];
}