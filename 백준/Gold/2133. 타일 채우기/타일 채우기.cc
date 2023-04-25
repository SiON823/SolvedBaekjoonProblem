#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long int ll;

int N;
int dp[31] = { 0 };

int main(void)
{
	ios_base::sync_with_stdio(0);
	
	cin >> N;

	dp[2] = 3;

	for (int i = 3; i <= N; i++ || i%2 == 0) {
		for (int j = i-2; j >= 0; j=j-2) {
			dp[i] += dp[j];
		}
		dp[i] = dp[i] * 2 + dp[i - 2] + 2;
	}

	cout << ((N%2 == 0) ? dp[N] : 0);
}