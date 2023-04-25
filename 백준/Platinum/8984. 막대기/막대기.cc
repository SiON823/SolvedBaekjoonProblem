#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

typedef long long int ll;

struct line { int up, down, len; };

bool cmp(const line& u, const line& v) {
	return make_pair(u.up, u.down) < make_pair(v.up, v.down);
}

ll up[100001];
ll down[100001];

int main()
{
	int n, m;
	cin >> n >> m;
	vector<line> a(n);
	vector<int> ups(n), downs(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i].up >> a[i].down;
		a[i].len = m + abs(a[i].up - a[i].down);
		ups[i] = a[i].up;
		downs[i] = a[i].down;
	}

	sort(ups.begin(), ups.end());
	sort(downs.begin(), downs.end());

	ups.erase(unique(ups.begin(), ups.end()), ups.end());
	downs.erase(unique(downs.begin(), downs.end()), downs.end());

	for (int i = 0; i < n; i++) {
		a[i].up = lower_bound(ups.begin(), ups.end(), a[i].up) - ups.begin();
		a[i].down = lower_bound(downs.begin(), downs.end(), a[i].down) - downs.begin();
	}
	
	sort(a.begin(), a.end(), cmp);
	for (int i = 0; i < n; i++) {
		ll temp = up[a[i].up];
		if (up[a[i].up] < down[a[i].down] + a[i].len) {
			up[a[i].up] = down[a[i].down] + a[i].len;
		}
		if (down[a[i].down] < temp + a[i].len) {
			down[a[i].down] = temp + a[i].len;
		}
	}

	ll ans = 0;
	for (int i = 0; i < n; i++) {
		if (ans < up[i]) {
			ans = up[i];
		}
		if (ans < down[i]) {
			ans = down[i];
		}
	}

	cout << ans << '\n';
	return 0;
}

