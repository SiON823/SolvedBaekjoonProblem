#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int coin[20];
int dp[10001];

int main(void)
{
	ios_base::sync_with_stdio(0);
	
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N;
		for (int i = 0; i < N; i++) cin >> coin[i];
		cin >> M;
		memset(dp, 0, sizeof(dp));

		dp[0] = 1;
		for (int i = 0; i < N; i++) {
			for (int j = coin[i]; j <= M; j++){
				dp[j] += dp[j - coin[i]];
			}
		}
		cout << dp[M] << '\n';
	}
	return 0;
}