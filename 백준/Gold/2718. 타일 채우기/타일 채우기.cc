#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long int ll;

ll dp[101] = { 0 };

const int x = 100;

int main(void)
{
	ios_base::sync_with_stdio(0);
	
	int T, N;

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 5;

	for (int i = 3; i <= x; i++) {
		for (int j = 1; j < i; j++) {
			if (j == i - 1) dp[i] += dp[j];
			else if (j == i - 2) dp[i] += 4 * dp[j];
			else if ((i - j) % 2 == 0) dp[i] += 3 * dp[j];
			else dp[i] += 2 * dp[j];
		}
		
		if (i % 2 == 0) dp[i] = dp[i] + 3;
		else dp[i] = dp[i] + 2;
	}

	cin >> T;
	while (T--) {
		cin >> N;
		cout << dp[N] << '\n';
	}
}