//https://acm.cs.nthu.edu.tw/contest/2305/
#include<bits/stdc++.h>
using namespace std;
/*
class house {
public:
	long long int x, y;
	house* front, * next;
};

bool check(house* p, long long int x, long long int y) {
	if (p->x == x && y - 1 <= p->y && p->y <= y + 1)
		return true;
	if (p->y == y && x - 1 <= p->x && p->x <= x + 1)
		return true;
	return false;
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
			long long int x, y;
			cin >> x >> y;
			house* tmp = new house;
			tmp->x = x, tmp->y = y;
			//Case 1 : the first house
			if (first == NULL) {
				tmp->next = NULL;
				tmp->front = NULL;
				first = tmp;
				last = tmp;
			}
			//Case 2 : insert before the first house
			else if ((y < first->y) || (y == first->y && x < first->x)) {
				tmp->next = first;
				first->front = tmp;
				tmp->front = NULL;
				first = tmp;
			}
			else {// insert after the first house
				house* p = first; // insert before p
				house* q = NULL;
				while (p && ((y == p->y && x > p->x) || (y > p->y))) {
					q = p;
					p = p->next;
				}
				//Case 3 : if that placeis already have the house, neglect it
				if (p && x == p->x && y == p->y) {
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
			long long int x, y;
			cin >> x >> y;
			house* p = first, * q = NULL;
			//Iterate the Linkedlist until it exceed the range
			while (p && (x + 1 >= p->x || y + 1 >= p->y)) {
				//Check for delete condition
				//Case 1 : Delete the first house
				if (p == first && check(p, x, y)) {
					house* tmp = p;
					first = first->next;
					if (first) first->front = NULL;
					p = p->next;
					delete tmp;
				}
				//Case 2 : Delete the house between first and last
				else if (p != last && check(p, x, y)) {
					house* tmp = p;
					q->next = p->next;
					p->next->front = q;
					p = p->next;
					delete tmp;
				}
				//Case 3 : Delete the last house
				else if (p == last && check(p, x, y)) {
					last = q;
					q->next = p->next;
					delete p;
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
				cout << '(' << p->x << ',' << p->y << ')' << endl;
				p = p->next;
			}
		}
		else { // PrintEnd
			cout << "PrintEnd" << endl;
			house* p = last;
			while (p) {
				cout << '(' << p->x << ',' << p->y << ')' << endl;
				p = p->front;
			}
		}
	}
	return 0;
}
*/
