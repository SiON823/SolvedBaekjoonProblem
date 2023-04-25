#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long int ll;

const int mod = 1000000007;

int S;
int x, y, z;
ll dp[51][51][51][51] = { 0 };

ll go(int n, int a, int b, int c) {
	if (n == 0) {
		if (a == 0 && b == 0 && c == 0) {
			return 1;
		}
		else return 0;
	}

	if (a < 0 || b < 0 || c < 0) {
		return 0;
	}

	ll& ans = dp[n][a][b][c];
	if (ans != -1) return ans;
	ans = 0;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				if (i + j + k == 0) continue;
				ans += go(n - 1, a - i, b - j, c - k);
			}
		}
	}

	ans %= mod;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	
	cin >> S >> x >> y >> z;

	memset(dp, -1, sizeof(dp));

	cout << go(S,x,y,z) << '\n';

	return 0;
}
