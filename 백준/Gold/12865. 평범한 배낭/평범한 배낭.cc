#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
typedef long long int ll;

const int INF = 987654321;

int dp[101][100001];

int main() {
	int N, K;
	vector<pair<int, int>> obj;

	cin >> N >> K;

	obj.resize(N + 1);

	for (int i = 1; i <= N; i++) {
		int x, y;
		cin >> x >> y;
		obj[i] = { x, y };
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j >= obj[i].first) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - obj[i].first] + obj[i].second);
			else dp[i][j] = dp[i - 1][j];
		}
	}

	cout << dp[N][K];
}