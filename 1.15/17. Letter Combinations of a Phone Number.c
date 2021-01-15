/*
https://leetcode.com/problems/letter-combinations-of-a-phone-number/	
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* phone[8] = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
void DFS(char* digits, int curr, int* reslen, char** res, char* tmp);

char** letterCombinations(char* digits, int* returnSize) {
	//initialize
	int len = strlen(digits);
	char** res = (char**)malloc(sizeof(char*) * 400);
	char* tmp = (char*)malloc(sizeof(char) * (len + 1));
	int reslen = 0;
	//prevent digits = ""
	if (len == 0) {
		*(returnSize) = 0;
		return res;
	}
	DFS(digits, 0, &reslen, res, tmp);
	*returnSize = reslen;
	return res;
}
void DFS(char* digits, int curr, int* reslen, char** res, char* tmp) {
	//end of one combination
	if (curr == strlen(digits)) {
		tmp[curr] = '\0';
		res[*reslen] = (char*)malloc(sizeof(char) * curr + 1);
		memcpy(res[*reslen], tmp, curr + 1);
		*(reslen) += 1;
		return;
	}
	char* phoneData = phone[digits[curr] - '0' - 2];
	for (int i = 0; i < strlen(phoneData); i++) {
		tmp[curr] = phoneData[i];
		DFS(digits, curr+1, reslen, res, tmp);
	}
}