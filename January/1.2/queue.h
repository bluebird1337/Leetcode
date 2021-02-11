#pragma once
#pragma once
#include<stdio.h>
#include<stdlib.h>

struct node {
	struct node* l_child;
	int data;
	struct node* r_child;
};
typedef struct node node;

struct Queue {
	int front;
	int rear;
	int size;
	node** data;
};
typedef struct Queue queue;

void create_queue(queue* q, int size) {
	q->size = size;
	q->front = q->rear = 0;
	q->data = (node**)malloc(sizeof(node*) * size);
}

void enqueue(queue* q, node* x) {
	if ((q->rear + 1) % q->size + 1 == q->front)
		printf("queue is fulled\n");
	else {
		q->rear = (q->rear + 1) % q->size;
		q->data[q->rear] = x;
	}
}

node* dequeue(queue* q) {
	node* x = NULL;
	if (q->front == q->rear)
		printf("queue is empty\n");
	else {
		q->front = (q->front + 1) % q->size;
		x = q->data[q->front];
	}
	return x;
}

int isEmpty(queue q) {
	return q.front == q.rear ? 1 : 0;
}