#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

typedef long long int ll;

ll dp[22];
ll c[22][22];

ll go(int n) 
{
	if (dp[n] != -1) return dp[n];
	ll& ans = dp[n];
	ans = 0;
	for (int i = 1; i <= n; i += 2) {
		ans += c[n - 1][i - 1] * go(i - 1) * go(n - i);
	}
	return ans;
}

int main()
{
	int T, N;
	c[0][0] = 1;
	for (int i = 1; i <= 20; i++) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j <= i - 1; j++) {
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
		}
	}

	memset(dp, -1, sizeof(dp));
	dp[0] = dp[1] = dp[2] = 1;
	
	cin >> T;

	while (T--) {
		cin >> N;
		if (N == 1) cout << 1 << '\n';
		else cout << 2LL * go(N) << '\n';
	}

	return 0;
}