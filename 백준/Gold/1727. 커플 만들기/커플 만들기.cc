#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int dp[1001][1001];

int main()
{
	int n, m;

	cin >> n >> m;

	vector<int> a(n + 1), b(m + 1);

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> b[i];
	}

	sort(a.begin() + 1, a.end());
	sort(b.begin() + 1, b.end());

	if (n > m) { swap(a, b); swap(n, m); }

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = dp[i - 1][j - 1] + abs(a[i] - b[j]);

			if (j - 1 >= i && dp[i][j] > dp[i][j - 1]) {
				dp[i][j] = dp[i][j - 1];
			}
		}
	}

	cout << dp[n][m] << '\n';

	return 0;
}