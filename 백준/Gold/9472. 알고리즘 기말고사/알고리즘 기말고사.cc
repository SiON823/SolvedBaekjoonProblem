#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

typedef long long int ll;

ll dp[18][18];

void find() {
	dp[1][0] = 1;
	dp[1][1] = 0;
	
	for (int i = 2; i <= 17; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				dp[i][0] = dp[i-1][0] * i;
			}
			else dp[i][j] = dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}
}

int main()
{
	memset(dp, -1, sizeof(dp));
	
	int T, t, N, K;

	find();

	cin >> T;

	while (T--) {
		cin >> t >> N >> K;

		cout << t << ' ' << dp[N][K] << '\n';

	}


	return 0;
}

