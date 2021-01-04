/*
Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.
*/
#pragma warning(disable:6011)
#include<stdio.h>
#include<stdlib.h>

//Definition for singly - linked list.
 struct ListNode {
	int val;
	struct ListNode* next;
};

 struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	 struct ListNode* first, * last;
	 if (l1 == NULL && l2 == NULL)
		 return NULL;

	 if (l1 == NULL) {
		 first = last = l2;
		 l2 = l2->next;
		 while (l2) {
			 last->next = l2;
			 l2 = l2->next;
			 last = last->next;
		 }
		 return first;
	 }

	 if (l2 == NULL) {
		 first = last = l1;
		 l1 = l1->next;
		 while (l1) {
			 last->next = l1;
			 l1 = l1->next;
			 last = last->next;
		 }
		 return first;
	 }

	 if (l1 && l2) {
		 if (l1->val > l2->val) {
			 first = last = l2;
			 l2 = l2->next;
		 }
		 else {
			 first = last = l1;
			 l1 = l1->next;
		 }

		 while (l1 && l2) {
			 if (l1->val > l2->val) {
				 last->next = l2;
				 l2 = l2->next;
				 last = last->next;
			 }
			 else {
				 last->next = l1;
				 l1 = l1->next;
				 last = last->next;
			 }
		 }

		 while (l1) {
			 last->next = l1;
			 l1 = l1->next;
			 last = last->next;
		 }
		 while (l2) {
			 last->next = l2;
			 l2 = l2->next;
			 last = last->next;
		 }
		 return first;
	 }
	
 }