#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <vector>

using namespace std;
typedef long long ll;

const ll mod = 100000;
string s;
ll d[200][200];
string open = "({[";
string close = ")}]";

ll go(int i, int j) {
	if (i > j) return 1;

	ll& ans = d[i][j];
	if (ans != -1) return ans;

	ans = 0;
	for (int k = i + 1; k <= j; k += 2) {
		for (int l = 0; l < 3; l++) {
			if (s[i] == open[l] || s[i] == '?') {
				if (s[k] == close[l] || s[k] == '?') {
					ll temp = go(i + 1, k - 1) * go(k + 1, j);
					ans += temp;
					if (ans >= mod) ans = mod + ans % mod;
				}
			}
		}
	}
	return ans;
}

int main()
{
	int n;
	cin >> n >> s;

	memset(d, -1, sizeof(d));
	ll ans = go(0, n - 1);

	if (ans >= mod) {
		printf("%05lld\n", ans % mod);
	}
	else {
		printf("%lld\n", ans);
	}

	return 0;
}
