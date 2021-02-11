/*
https://leetcode.com/problems/word-ladder-ii/
*/
#pragma warning(disable:6011)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node {
	char* word;
	int level; //record level of tree
	struct node* next;
}node;
node* front = NULL;
node* last = NULL;
	
int isEmpty() {
	return front == NULL ? 1 : 0;
}

void enqueue(char*word) {
	node* t = malloc(sizeof(node));
	t->word = word;
	t->next = NULL;
	if (front == NULL) {
		front = t;
		last = t;
	}
	else {
		last->next = t;
		last = t;
	}
}

node* dequeue() {
	node* p;
	p = front;
	front = front->next;
	return p;
}

int check(char* a, char* b) { // if two string is same or Only one letter is different, return true
	int count = 0, i = 0;
	while (a[i] != '\0') {
		if (a[i] != b[i])
			count++;
		i++;
	}
	if (count < 2)
		return 1;
	else
		return 0;
}

int ladderLength(char* beginWord, char* endWord, char** wordList, int wordListSize) {
	//initialize
	int* visited = (int*)calloc(wordListSize, sizeof(int));
	int flag = 0, j; // flag used for decide when to break while loop
	enqueue(beginWord);
	last->level = 1;
	node* tmp = NULL;

	//BFS
	while (!isEmpty() && flag == 0) {
		tmp = dequeue();
		for (j = 0; j < wordListSize; j++) {
			if (visited[j] == 0 && check(tmp->word, wordList[j])) {
				if (strcmp(wordList[j], endWord) == 0) {
					//if endWord is found, go out of for&while loop 
					flag= 1;
					break;
				}
				else {
					//if found a string that Only one letter is different but not endWord, enqueue it and record its level
					enqueue(wordList[j]);
					visited[j]++;
					last->level = tmp->level + 1;
				}
			}
		}
	}
	//flag == 0 : endWord not found
	//flag == 1 : endWord was found, and increase the level by 1
	return flag == 0 ? 0 : tmp->level + 1;
}

int main() {
	char beginWord[] = "hot", endWord[] = "dog";
	char* wordList[6];
	for (int i = 0; i < 2; i++) {
		wordList[i] = (char*)malloc(sizeof(char) * 3);
	}
	wordList[0] = "hot", wordList[1] = "dog";


	printf("%d", ladderLength(beginWord, endWord, wordList, 2));

	return 0;
}