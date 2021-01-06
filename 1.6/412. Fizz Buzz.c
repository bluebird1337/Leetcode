/*

https://leetcode.com/problems/fizz-buzz/

Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output ¡§Fizz¡¨ instead of the number and for the multiples of five output ¡§Buzz¡¨. For numbers which are multiples of both three and five output ¡§FizzBuzz¡¨.
*/
#include<stdio.h>
#include<string.h>

char** fizzBuzz(int n, int* returnSize) {
	char** ret = (char**)malloc(sizeof(char*) * n);
	char tmp[9];
	*returnSize = n;

	for (int i = 1; i <= n; i++) {
		if (i % 15 == 0)	sprintf(tmp, "%s", "FizzBuzz");
		else if (i % 3 == 0) sprintf(tmp, "%s", "Fizz");
		else if (i % 5 == 0) sprintf(tmp, "%s", "Buzz");
		else sprintf(tmp, "%d", i);
		
		ret[i - 1] = malloc(sizeof(tmp) );
		memcpy(ret[i - 1], tmp, strlen(tmp)+1);
		memset(tmp, "", 9);
	}
	return ret;
}