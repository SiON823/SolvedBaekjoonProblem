#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

int T, N, K;
int dp[101][101][2];

int main() {
	scanf("%d", &T);

	dp[1][0][0] = 1;
	dp[1][0][1] = 1;

	for (int i = 2; i < 101; i++) {
		for (int j = 0; j < i; j++) {
			dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
			dp[i][j][1] = dp[i - 1][j][0] + dp[i - 1][j - 1][1];
		}
	}

	for (int i = 0; i < T; i++) {
		scanf("%d %d", &N, &K);
		printf("%d\n", dp[N][K][0] + dp[N][K][1]);
	}

	return 0;
}