/*

https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/

Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.

A string is represented by an array if the array elements concatenated in order forms the string.

Constraints:

1 <= word1.length, word2.length <= 103
1 <= word1[i].length, word2[i].length <= 103
1 <= sum(word1[i].length), sum(word2[i].length) <= 103
word1[i] and word2[i] consist of lowercase letters.

*/
#pragma warning(disable:4996)
#include<stdio.h>
#include <stdbool.h>
#include<stdlib.h>
#include<string.h>

bool arrayStringsAreEqual(char** word1, int word1Size, char** word2, int word2Size) {
    int word1Lenght = 0;
    int word2Lenght = 0;
    int word1SizeIndex = word1Size;
    int word2SizeIndex = word2Size;
    char* word_1 = NULL;
    char* word_2 = NULL;
    while (word1SizeIndex != 0 || word2SizeIndex != 0) {
        if (word1SizeIndex > 0) {
            word1Lenght += strlen(word1[word1SizeIndex - 1]);
            word1SizeIndex--;
        }
        if (word2SizeIndex > 0) {
            word2Lenght += strlen(word2[word2SizeIndex - 1]);
            word2SizeIndex--;
        }
    }

    word_1 = malloc(word1Lenght + 1);
    word_2 = malloc(word2Lenght + 1);
    word1Lenght = 0;
    word2Lenght = 0;
    while (word1SizeIndex < word1Size || word2SizeIndex < word2Size) {
        if (word1SizeIndex < word1Size) {
            strcpy(word_1 + (word1Lenght), word1[word1SizeIndex]);
            word1Lenght += strlen(word1[word1SizeIndex]);
            word1SizeIndex++;
        }
        if (word2SizeIndex < word2Size) {
            strcpy(word_2 + (word2Lenght), word2[word2SizeIndex]);
            word2Lenght += strlen(word2[word2SizeIndex]);
            word2SizeIndex++;
        }
    }
    word_1[word1Lenght] = '\0';
    word_2[word2Lenght] = '\0';
    return strcmp(word_1, word_2) == 0;
}