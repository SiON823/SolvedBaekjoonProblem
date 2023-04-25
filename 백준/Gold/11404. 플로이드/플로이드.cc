#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
typedef long long int ll;

const int INF = 987654321;

int dp[102][102];
int N;
int M;

void Floyd() {
	for (int m = 1; m <= N; m++) {
		for (int s = 1; s <= N; s++) {
			for (int e = 1; e <= N; e++) {
				dp[s][e] = min(dp[s][e], dp[s][m] + dp[m][e]);
			}
		}
	}
}

int main() {
	cin >> N;
	cin >> M;


	fill(dp[0], dp[101], INF);

	for (int i = 1; i <= N; i++) {
		dp[i][i] = 0;
	}
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		dp[a][b] = min(dp[a][b], c);
	}

	Floyd();

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (dp[i][j] == INF) dp[i][j] = 0;
			cout << dp[i][j] << ' ';
		}
		cout << '\n';
	}
}