#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int food[301][301];
int dp[301][301];

int main(void)
{
	ios_base::sync_with_stdio(0);
	int N, M, K;
	cin >> N >> M >> K;
	while (K--) {
		int x, y, z;
		cin >> x >> y >> z;
		if (food[x][y] < z) food[x][y] = z;
	}

	memset(dp, -1, sizeof(dp));

	dp[1][1] = 0;

	for (int j = 1; j <= M - 1; j++) {
		for (int i = 1; i <= N; i++) {
			if (dp[i][j] == -1) continue;

			for (int k = i + 1; k <= N; k++) {
				if (food[i][k] > 0) {
					dp[k][j + 1] = max(dp[k][j + 1], dp[i][j] + food[i][k]);
				}
			}
		}
	}

	int res = 0;
	for (int i = 2; i <= M; i++) {
		res = max(res, dp[N][i]);
	}

	cout << res << '\n';

	return 0;
}