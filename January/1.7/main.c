#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int lengthOfLongestSubstring(char* s);
int lengthOfLongestSubstring2(char* s);

int main() {

	char s[10] = { "abcabcbb" };

	printf("%d", lengthOfLongestSubstring2(s));

	return 0;
}