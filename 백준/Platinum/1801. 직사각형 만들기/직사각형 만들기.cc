#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int a[16];
bool dp[81][81][81][81];

int main(void)
{
	ios_base::sync_with_stdio(0);
	
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i];

	dp[0][0][0][0] = true;

	for (int i = 0; i < N; i++) {
		for (int x1 = 80; x1 >= 0; x1--) {
			for (int x2 = 80; x2 >= 0; x2--) {
				for (int x3 = 80; x3 >= 0; x3--) {
					for (int x4 = 80; x4 >= 0; x4--) {
						if (dp[x1][x2][x3][x4] == false) continue;

						if (x1 + a[i] <= 80) dp[x1 + a[i]][x2][x3][x4] = true;
						if (x2 + a[i] <= 80) dp[x1][x2 + a[i]][x3][x4] = true;
						if (x3 + a[i] <= 80) dp[x1][x2][x3 + a[i]][x4] = true;
						if (x4 + a[i] <= 80) dp[x1][x2][x3][x4 + a[i]] = true;
					}
				}
			}
		}
	}

	int ans = -1;
	for (int i = 1; i <= 80; i++) {
		for (int j = 1; j <= 80; j++) {
			if (dp[i][j][i][j] && i * j > ans) ans = i * j;
		}
	}
	cout << ans << '\n';

	return 0;
}