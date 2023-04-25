#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long int ll;

typedef pair<pair<int, int>, int> gilsu;
vector<gilsu> node;
int dp[501];

const int INF = 987654321;
int TC, N, M, W;

void BellmanFord(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < node.size(); j++) {
			int from = node[j].first.first;
			int to = node[j].first.second;
			int cost = node[j].second;

			dp[to] = min(dp[to], dp[from] + cost);
		}
	}

	for (int i = 0; i < node.size(); i++) {
		int from = node[i].first.first;
		int to = node[i].first.second;
		int cost = node[i].second;
		if (dp[from] + cost < dp[to]) {
			cout << "YES" << '\n';
			return;
		}
	}

	cout << "NO" << '\n';
}


int main() {
	cin >> TC;

	while (TC--) {
		node.clear();
		for (int i = 1; i <= N; i++) dp[i] = INF;

		cin >> N >> M >> W;

		for (int i = 0; i < M; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			node.push_back({ {a, b}, c });
			node.push_back({ {b, a}, c });
		}
		for (int i = 0; i < W; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			node.push_back({{ a,b }, -c});
		}

		BellmanFord(N);
	}

	return 0;
}