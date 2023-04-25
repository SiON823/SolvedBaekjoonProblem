#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
typedef long long int ll;

int parent[100001];
vector<int> node[100001];

void BFS() {
	queue<int> Q;
	Q.push(1);

	while (!Q.empty()) {
		int root = Q.front();
		Q.pop();

		int size = node[root].size();
		for (int i = 0; i < size; i++) {
			if (parent[root] == node[root][i]) continue;
			Q.push(node[root][i]);
			parent[node[root][i]] = root;
		}
	}

	return;
}

int main() {
	int N;
	cin >> N;

	for (int i = 1; i < N; i++) {
		int a, b;
		cin >> a >> b;

		node[a].push_back(b);
		node[b].push_back(a);
	}
	BFS();

	for (int i = 2; i <= N; i++) cout << parent[i] << '\n';
}