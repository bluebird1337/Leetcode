/*
* https://leetcode.com/problems/determine-if-two-strings-are-close/
Two strings are considered close if you can attain one from the other using the following operations:

Operation 1: Swap any two existing characters.
For example, abcde -> aecdb
Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
You can use the operations on either string as many times as necessary.

Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.
Constraints:

1 <= word1.length, word2.length <= 105
word1 and word2 contain only lowercase English letters.
*/
    #include<iostream>
    using namespace std;
    #include<cstring>
    #include <map>


    class Solution {
    public:
        bool closeStrings(string word1, string word2) {
            //if the length of two string is different -> false
            int len1, len2;
            len1 = word1.length(), len2 = word2.length();
            if (len1 != len2)
                return false;
            //Enter data of appearance, letter, frequency
            map<int, int>frequency;
            map<int, int>::iterator iter;
            int letter1[26] = { 0 }, letter2[26] = { 0 };
            for (int i = 0; i < len1; i++) {
                letter1[word1[i] - 'a']++;
                letter2[word2[i] - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                frequency[letter1[i]]++;
            }
            //check whether two strings has the same letter appearance
            for (int i = 0; i < 26; i++) {
                if ((letter1[i] != 0 && letter2[i] == 0) || (letter2[i] != 0 && letter1[i] == 0))
                    return false;
            }
            //check the overall frequency
            for (int i = 0; i < 26; i++) {
                frequency[letter2[i]]--;
            }
            for (iter = frequency.begin(); iter != frequency.end(); iter++) {
                if (iter->second != 0)
                    return false;
            }
            return true;
        }
    };