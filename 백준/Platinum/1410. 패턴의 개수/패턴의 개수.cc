#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <vector>

using namespace std;
typedef long long ll;

const int mod = 1000003;
int d[50][1 << 15];

int main()
{
	int n, k;
	cin >> n >> k;

	vector<string> p(n);

	for (int i = 0; i < n; i++) cin >> p[i];

	int m = p[0].size();
	for (int i = 0; i < m; i++) {
		for (char c = 'a'; c <= 'z'; c++) {
			int v = 0;
			for (int j = 0; j < n; j++) {
				if (p[j][i] == c || p[j][i] == '?') {
					v |= (1 << j);
				}
			}
			if (i == 0) d[i][v] += 1;
			else {
				for (int j = 0; j < (1 << n); j++) {
					d[i][j & v] = (d[i][j & v] + d[i - 1][j]) % mod;
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < (1 << n); i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) cnt++;
		}

		if (cnt == k) {
			ans += d[m - 1][i];
			ans %= mod;
		}
	}
	cout << ans << '\n';
	return 0;
}
