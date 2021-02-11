#pragma warning(disable:6011)
#pragma warning(disable:4996)
#pragma warning(disable:6031)
#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

node* root;

void create_tree() {
	queue q;
	create_queue(&q, 100);

	printf("enter root value:\n");
	root = (node*)malloc(sizeof(node));
	scanf("%d", &root->data);
	root->l_child = root->r_child = NULL;
	enqueue(&q, root);

	while (!isEmpty(q)) {
		int x;
		node* p = dequeue(&q);

		printf("enter %d left child:\n", p->data);
		scanf("%d", &x);
		if (x != -1) {
			node* t;
			t = (node*)malloc(sizeof(node));
			t->data = x;
			t->l_child = t->r_child = NULL;
			p->l_child = t;
			enqueue(&q, t);
		}

		printf("enter %d right child:\n", p->data);
		scanf("%d", &x);
		if (x != -1) {
			node* t;
			t = (node*)malloc(sizeof(node));
			t->data = x;
			t->l_child = t->r_child = NULL;
			p->r_child = t;
			enqueue(&q, t);
		}
	}
}

void preorder(node* p) {
	if (p) {
		printf("%d ", p->data);
		preorder(p->l_child);
		preorder(p->r_child);
	}
}

int main() {
	

	return 0;
}