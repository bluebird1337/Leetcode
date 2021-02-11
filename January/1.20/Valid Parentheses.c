/*
https://leetcode.com/problems/valid-parentheses/
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

bool isValid(char* s) {
	int len = strlen(s);
	char* stack = (char*)malloc(sizeof(char) * (len));
	int top = -1;
	int i = 0;
	for(int i=0 ;i<len ; i++){
		if (s[i] == '(' || s[i] == '[' || s[i] == '{') { //insert
			top++;
			stack[top] = s[i];
		}
		else { //pop
			if (top >= 0) {
				char tmp = stack[top--];
				if (tmp == '(') {
					if (s[i] != ')')
						return false;
				}
				if (tmp == '[') {
					if (s[i] != ']')
						return false;
				}
				if (tmp == '{') {
					if (s[i] != '}')
						return false;
				}
			}
			else
				return false;
		}
	}
	if (top != -1)
		return false;

	return true;
}

int main() {
	char s[] = "([)]";
	if (isValid(s))
		printf("true");
	else
		printf("false");
	return 0;
}