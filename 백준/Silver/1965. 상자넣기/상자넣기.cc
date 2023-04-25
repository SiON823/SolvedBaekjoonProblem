#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int box[1001];
int dp[1001];

int main(void)
{
	ios_base::sync_with_stdio(0);
	
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> box[i];
	
	for (int i = 1; i <= N; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (box[j] < box[i]) dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	int res = 1;
	for (int i = 1; i <= N; i++) if (res < dp[i]) res = dp[i];

	cout << res << '\n';

	return 0;
}