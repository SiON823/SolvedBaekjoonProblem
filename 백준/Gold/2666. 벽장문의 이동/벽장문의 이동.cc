#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int M;

int door[20];
int dp[20][21][21];

int go(int i, int d1, int d2) {
	if (i == M) return 0;

	int& ans = dp[i][d1][d2];

	if (ans != -1) return ans;

	ans = min(go(i + 1, door[i], d2) + abs(door[i] - d1),
			go(i + 1, d1, door[i]) + abs(door[i] - d2));
	return ans;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	
	int N;
	int d1, d2;
	cin >> N;
	cin >> d1 >> d2;
	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> door[i];
	}

	memset(dp, -1, sizeof(dp));
	cout << go(0, d1, d2) << '\n';

	return 0;
}