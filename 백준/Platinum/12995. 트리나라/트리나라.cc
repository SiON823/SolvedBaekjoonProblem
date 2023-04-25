#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
typedef long long int ll;

const ll mod = 1000000007;
vector<int> g[51]; //입력
vector<int> a[51]; //트리

ll dp[51][51][51];

int N, K;

void tree(int x, int pa) {
	for (int y : g[x]) {
		if (y == pa) continue;

		a[x].push_back(y);
		tree(y, x);
	}
}

ll go(int x, int k, int e) {
	ll& ans = dp[x][k][e];
	if (ans != -1) return ans;
	if (k == 0) {
		return 1;
	}

	if (e == a[x].size()) {
		if (k == 1) {
			return 1;
		}
		else return 0;
	}
	ans = 0;

	for (int i = 0; i < k; i++) {
		ll t1 = go(a[x][e], i, 0);
		ll t2 = go(x, k - i, e + 1);

		ans += t1 * t2;
		ans %= mod;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	
	cin >> N >> K;

	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		u -= 1;
		v -= 1;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	tree(0, -1);
	memset(dp, -1, sizeof(dp));
	ll ans = 0;

	for (int i = 0; i < N; i++) {
		ans += go(i, K, 0);
	}

	ans %= mod;

	cout << ans << '\n';
	
	return 0;
}
