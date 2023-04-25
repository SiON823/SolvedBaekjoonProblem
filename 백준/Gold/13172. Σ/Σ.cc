#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <numeric>

using namespace std;
typedef long long int ll;
const ll mod = 1000000007;

ll pow(ll x, ll y) {
	if (y == 1) return x;
	
	if (y % 2 == 0) return pow(x, y / 2) * pow(x, y / 2) % mod;
	else return pow(x, y - 1) * x % mod;
}

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int main() {
	ll m, a, b;
	ll ans = 0;

	cin >> m;

	while (m--) {
		cin >> b >> a;
		ll g = gcd(a, b);
		b /= g;
		a /= g;
		ans += a * pow(b, mod - 2) % mod;
		ans %= mod;
	}

	cout << ans << '\n';
	
}