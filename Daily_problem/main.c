#pragma warning(disable:4996)
#pragma warning(disable:6031)
#pragma warning(disable:6011)
#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

//tree basic function
node* create_tree(node*root) {
	queue q;
	create_queue(&q, 100);

	printf("enter root value:\n");
	root = (node*)malloc(sizeof(node));
	scanf("%d", &root->val);
	root->left = root->right = NULL;
	enqueue(&q, root);

	while (!isEmpty(q)) {
		int x;
		node* p = dequeue(&q);

		printf("enter %d left child:\n", p->val);
		scanf("%d", &x);
		if (x != -1) {
			node* t;
			t = (node*)malloc(sizeof(node));
			t->val = x;
			t->left = t->right = NULL;
			p->left = t;
			enqueue(&q, t);
		}

		printf("enter %d right child:\n", p->val);
		scanf("%d", &x);
		if (x != -1) {
			node* t;
			t = (node*)malloc(sizeof(node));
			t->val = x;
			t->left = t->right = NULL;
			p->right = t;
			enqueue(&q, t);
		}
	}
	return root;
}

void preorder(node* p) {
	if (p) {
		printf("%d ", p->val);
		preorder(p->left);
		preorder(p->right);
	}
}
//
//other functions
node* invert(node* root);
//
int main() {
	node* root = NULL;
	root = create_tree(root);
	preorder(root);
	root = invert(root);
	printf("\n");
	preorder(root);
	return 0;
}