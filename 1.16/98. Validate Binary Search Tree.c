/*
https://leetcode.com/problems/validate-binary-search-tree/

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1
*/
#pragma warning(disable:6011)
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};
typedef struct TreeNode node;

typedef struct stack {
	int top;
	node** data;
	int size;
}stack;


void create(stack*st, int size) {
	st->data = (node**)malloc(sizeof(node*) * size);
	st->top = -1;
	st->size = size;
}
int isEmpty(stack st) {
	return st.top == -1 ? 1 : 0;
}
void push(node*data, stack* st) {
	st->top++;
	st->data[st->top] = data;
}
node* pop(stack* st) {
	return st->data[st->top--];
}

bool isValidBST(struct TreeNode* root) {
	if (root == NULL)
		return NULL;
	stack st;
	create(&st, 10000);
	node* pre = NULL;
	while (root || !isEmpty(st)) {
		if (root != NULL) {
			push(root, &st);
			root = root->left;
		}
		else {
			root = pop(&st);
			if (pre != NULL && root->val <= pre->val) return false;
			pre = root;
			root = root->right;
		}
	}

	return true;
}



int main() {
	node* root = (node*)malloc(sizeof(node));
	root->val = 1;

	root->left = (node*)malloc(sizeof(node));	
	root->left->val = 2	;
	root->left->left = root->left->right = NULL;
	root->right = (node*)malloc(sizeof(node));
	root->right->val = 3;
	root->right->left = root->right->right = NULL;
	/*
	root->right = (node*)malloc(sizeof(node));
	root->right->val = 4;
	root->right->left = (node*)malloc(sizeof(node));
	root->right->right = (node*)malloc(sizeof(node));

	root->right->left->val = 3;
	root->right->right->val = 6;
	root->right->left->left = root->right->left->right = NULL;
	root->right->right->left = root->right->right->right = NULL;
	*/

	isValidBST(root);

	return 0;
}