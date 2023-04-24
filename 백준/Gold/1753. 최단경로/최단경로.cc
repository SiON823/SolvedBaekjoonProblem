#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long int ll;

int dp[20001];
vector<pair<int, int>> node[20001];

const int INF = 987654321;
int V, E, K;

void go(int x) {
	priority_queue<pair<int, int>> Q;

	Q.push({ 0, x });
	dp[x] = 0;

	while (!Q.empty()) {
		int d = -Q.top().first;
		int cur = Q.top().second;

		Q.pop();

		if (dp[cur] < d) continue;

		for (int i = 0; i < node[cur].size(); i++) {
			int cost = d + node[cur][i].second;
			
			if (cost < dp[node[cur][i].first]) {
				dp[node[cur][i].first] = cost;
				Q.push({ -cost, node[cur][i].first });
			}
		}
	}

}

int main() {
	for (int i = 0; i < 20001; i++) {
		dp[i] = INF;
	}
	
	cin >> V >> E;
	cin >> K;

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		node[a].push_back({ b, c });
	}

	go(K);

	for (int i = 1; i <= V; i++) {
		if (dp[i] == INF) cout << "INF" << '\n';
		else cout << dp[i] << '\n';
	}


	return 0;
}