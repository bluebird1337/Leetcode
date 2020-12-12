#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

int main() {
	struct TreeNode* t1 = NULL, * t2 = NULL;
	t1 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	t2 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	t1->val = 1, t1->left->val = 3, t1->right->val = 2, t1->left->left->val = 5;
	t2->val = 2, t2->left->val = 1, t2->right->val = 3, t2->left->right->val = 4, t2->right->right->val = 7;

}