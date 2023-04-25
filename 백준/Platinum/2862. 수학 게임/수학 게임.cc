#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

typedef long long int ll;

int main() {
	vector<ll> fib;
	ll n;
	cin >> n;

	ll a = 1, b = 1;

	while (b <= n) {
		fib.push_back(b);
		ll temp = b;
		b = a + b;
		a = temp;
	}

	ll last = -1;

	//제켄도르프 분해
	for (int i = fib.size() - 1; i >= 0; i--) {
		if (n - fib[i] >= 0) {
			last = fib[i];
			n -= last;
		}
	}

	cout << last << '\n';
	return 0;
}