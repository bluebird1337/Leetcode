#include <bits/stdc++.h>
using namespace std;

void DFS(vector<pair<int, int>>data, int index, int k, int& lightest, int curr_w, int sum) {
	if (index >= data.size()){
		if (sum >= k) {
			lightest = lightest < curr_w ? lightest : curr_w;
		}
		return;
	}
	DFS(data, index + 1, k, lightest, curr_w + data[index].second, sum + data[index].first);
	DFS(data, index + 1, k, lightest, curr_w, sum);
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>>data;
	for (int i = 0; i < n; i++) {
		int value, weight;
		cin >> value >> weight;
		auto d = make_pair(value, weight);
		data.push_back(d);
	}
	int lightest = INT_MAX;
	DFS(data, 0, k, lightest, 0, 0);
	cout << lightest << endl;
	return 0;
}
