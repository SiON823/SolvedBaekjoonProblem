#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>
#include <math.h>
#include <map>

using namespace std;

typedef long long int ll;

ll phi(ll n) {
	ll res = n;
	ll p = 2;
	while (p * p <= n) {
		if (n % p == 0) res = res / p * (p - 1);
		while (n % p == 0) n /= p;
		p++;
	}
	if (n != 1) res = res / n * (n - 1);
	return res;
}

ll pow(ll a, ll b, ll c) {
	ll res = 1;
	while (b) {
		if (b & 1) res = (res*a) % c;
		b >>= 1;
		a = (a*a) % c;
	}
	return res;
}

ll solve(ll n, ll m){
	if (m == 1) {
		return 0;
	}
	ll pi = phi(m);
	ll t = solve(n, pi);
	return pow(n, t + pi, m);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		ll N, M;
		cin >> N >> M;
		cout << solve(N, M) % M <<'\n';
	}

}

