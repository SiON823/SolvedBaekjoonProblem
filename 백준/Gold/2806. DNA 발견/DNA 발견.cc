#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long int ll;

int f[1000001];
int g[1000001];

int main() {
	ios_base::sync_with_stdio(0);
	
	int len;
	string s;

	cin >> len >> s;
	s = " " + s;

	f[0] = 0;
	g[0] = 0;
	for (int i = 1; i <= len; i++) {
		if (s[i] == 'A') {
			f[i] = f[i - 1];
			g[i] = min(f[i - 1], g[i - 1]) + 1;
		}
		else {
			f[i] = min(f[i - 1], g[i - 1]) + 1;
			g[i] = g[i - 1];
		}
	}

	cout << f[len] << '\n';
	return 0;
}
