//226. Invert Binary Tree
#include<stdio.h>
struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};
typedef struct TreeNode node;

struct TreeNode* invertTree(struct TreeNode* root) {
	if (root == NULL)
		return NULL;
	if (root->left == NULL && root->right == NULL)
		return root;
	if (root->left == NULL) {
		root->left = root->right;
		root->right = NULL;
		root->left = invertTree(root->left);
		return root;
	}
	if (root->right == NULL) {
		root->right = root->left;
		root->left = NULL;
		root->right = invertTree(root->right);
		return root;
	}

	struct TreeNode* tmp = root->left;
	root->left = root->right;
	root->right = tmp;
	root->left = invertTree(root->left);
	root->right = invertTree(root->right);

	return root;
}