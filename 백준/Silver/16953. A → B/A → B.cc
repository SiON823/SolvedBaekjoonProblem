#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
typedef long long int ll;

void solve(ll N, ll M, int cnt, int check) {
	if (N == M) {
		cout << cnt + 1 << '\n';
		exit(0);
	}
	if (N > M) {
		if (check == 0) {
			cout << -1 << '\n';
			exit(0);
		}
		return;
	}

	solve(10 * N + 1, M, cnt + 1, check+1);
	solve(2 * N, M, cnt + 1, check);
}

int main() {
	ll N, M;
	cin >> N >> M;


	solve(N, M, 0, 0);

	return 0;
}