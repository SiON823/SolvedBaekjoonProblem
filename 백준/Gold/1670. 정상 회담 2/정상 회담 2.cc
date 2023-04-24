#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;
typedef long long ll;

ll dp[10000] = {0};
int N;

int main()
{
	scanf("%d", &N);

	dp[0] = 1;

	if (N == 0) { printf("1"); return 0; }

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j<=i-2; j++) {
			dp[i] += dp[j] * dp[i - j - 2];
			dp[i] %= 987654321LL;
		}
	}

	printf("%lld", dp[N]);
}
