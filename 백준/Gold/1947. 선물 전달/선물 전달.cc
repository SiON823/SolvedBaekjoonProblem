#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long int ll;

int N;
ll dp[1000001];

const ll mod = 1000000000;

int main(void)
{
	ios_base::sync_with_stdio(0);
	
	cin >> N;

	dp[1] = 0;
	dp[2] = 1;

	for (int i = 3; i <= N; i++) {
		dp[i] = ((i - 1) * (dp[i - 1] + dp[i - 2]))%mod;
	}

	cout << dp[N];
}