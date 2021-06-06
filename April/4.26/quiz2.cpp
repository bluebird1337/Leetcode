//https://acm.cs.nthu.edu.tw/contest/2318/

#include<bits/stdc++.h>
using namespace std;

class house {
public:
	long long int x;
	house* front, * next;
};

bool check(house* p, long long int left, long long int right) {
	return p->x >= left && p->x <= right;
}

int main() {
	int N;
	cin >> N;
	house* first = NULL;
	house* last = NULL;
	while (N--) {
		string command;
		cin >> command;
		if (command == "House") {
			long long int x;
			cin >> x;
			house* tmp = new house;
			tmp->x = x;
			//Case 1 : First house
			if (!first) {
				tmp->next = NULL;
				tmp->front = NULL;
				first = tmp;
				last = tmp;
			}
			//Case 2 : insert before the first house
			else if (x<first->x) {
				tmp->next = first;
				first->front = tmp;
				tmp->front = NULL;
				first = tmp;
			}
			else {// insert after the first house
				house* p = first; // insert before p
				house* q = NULL;
				while (p && p->x < x) {
					q = p;
					p = p->next;
				}
				//Case 3 : if that place is already have the house, neglect it
				if (p && x == p->x ) {
					delete tmp;
					continue;
				}
				//Case 4 : insert after the first house & before the last house
				else if (p) { // p->x > x || (p->x == x && p->y > y)
					tmp->next = p;
					tmp->front = q;
					if (q)q->next = tmp;
					p->front = tmp;
				}
				//Case 5 : insert after the last house
				else {
					tmp->next = q->next;
					if (q)q->next = tmp;
					tmp->front = q;
					last = tmp;
				}
			}
		}
		else if (command == "Bomb") {
			long long int a, d;
			cin >> a >> d;
			long long int left = a - d, right = a + d;
			house* p = first, * q = NULL;
			//Iterate the Linkedlist until it exceed the range
			while (p && p->x <= right) {
				//Check for delete condition
				//Case 1 : Delete the first house
				if (p == first && check(p, left, right)) {
					house* tmp = p;
					first = first->next;
					if (first) first->front = NULL;
					p = p->next;
					delete tmp;
				}
				//Case 2 : Delete the house between first and last
				else if (p != last && check(p, left, right)) {
					house* tmp = p;
					q->next = p->next;
					p->next->front = q;
					p = p->next;
					delete tmp;
				}
				//Case 3 : Delete the last house
				else if (p == last && check(p, left, right)) {
					last = q;
					q->next = p->next;
					p = NULL;
				}
				else {
					q = p;
					p = p->next;
				}
			}
		}
		else if (command == "PrintFront") {
			cout << "PrintFront" << endl;
			house* p = first;
			while (p) {
				cout << p->x << endl;
				p = p->next;
			}
		}
		else { // PrintEnd
			cout << "PrintEnd" << endl;
			house* p = last;
			while (p) {
				cout << p->x << endl;
				p = p->front;
			}
		}
	}
	return 0;
}
