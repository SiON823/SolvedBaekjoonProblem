#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
typedef long long int ll;

const int mod = 1000000007;

ll fact[1000001];
ll inv[1000001];
ll fact_inv[1000001];

ll comb(int n, int k) {
	if (k<0 || k>n) return 0;

	ll ans = fact[n];
	ans = (ans * fact_inv[k]) % mod;
	ans = (ans * fact_inv[n - k]) % mod;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	fact[0] = 1;

	for (int i = 1; i <= n; i++) {
		fact[i] = (fact[i - 1] * i) % mod;
	}
	
	inv[1] = 1;
	for (int i = 2; i <= n; i++) {
		inv[i] = (inv[mod % i] * (mod - mod / i)) % mod;
	}

	fact_inv[0] = 1;
	for (int i = 1; i <= n; i++) {
		fact_inv[i] = (fact_inv[i - 1] * inv[i]) % mod;
	}

	ll ans = 0;
	ll sign = 1;

	for (int i = 0; i <= n; i++) {
		ll temp = (comb(n, i) * comb(n - i, a)) % mod;
		temp = (temp * comb(n - i, b)) % mod;
		temp = (temp * comb(n - i, c)) % mod;

		ans += sign * temp;
		ans %= mod;
		ans = (ans + mod) % mod;
		sign = -sign;
	}

	cout << ans << '\n';

	return 0;
}
