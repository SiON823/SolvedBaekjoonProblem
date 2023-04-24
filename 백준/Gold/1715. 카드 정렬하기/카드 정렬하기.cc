#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long int ll;


int N;
priority_queue<int, vector<int>, greater<int>> Q;

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	cin >> N;

	if (N == 1) {
		cout << 0 << '\n';
		return 0;
	}

	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		Q.push(a);
	}
	int ans = 0;

	while (Q.size() != 1) {
		int a = Q.top();
		Q.pop();
		int b = Q.top();
		Q.pop();
		ans += a + b;
		Q.push(a + b);
	}
	cout << ans << '\n';

	return 0;
}