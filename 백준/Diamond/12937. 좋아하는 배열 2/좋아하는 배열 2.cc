#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long int ll;

const ll mod = 1000000007;

ll powk[50001];
ll divseq[21];
ll dp[21][50001];
ll good[50001];
ll bad[50001];

int N, K;

int main()
{
	cin >> N >> K;
	powk[0] = 1;

	for (int i = 1; i <= N; i++) {
		powk[i] = (K * powk[i - 1]) % mod;
	}

	for (int i = 0; i <= K; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= 20; i++) {
		for (int l = 1; l <= K; l++) {
			for (int j = 2 * l; j <= K; j += l) {
				dp[i][j] += dp[i - 1][l];
			}
		}
		for (int j = 0; j <= K; j++) {
			divseq[i] += dp[i][j];
			divseq[i] %= mod;
		}
	}

	bad[0] = 0;
	good[0] = 1;

	for (int i = 1; i <= N; i++) {
		bad[i] = (bad[i - 1] * K) % mod;
		for (int j = 2; j <= i && j <= 20; j++) {
			ll sign = 1;
			if (j % 2 == 1) sign = mod - 1;

			ll p = sign;
			ll q = good[i - j];
			ll r = divseq[j];

			bad[i] += (((p * q) % mod) * r) % mod;
		}

		bad[i] %= mod;
		good[i] = (powk[i] + mod - bad[i]) % mod;
	}

	cout << good[N] << '\n';

	return 0;

}