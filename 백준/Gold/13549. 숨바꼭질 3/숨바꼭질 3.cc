#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <queue>

using namespace std;
typedef long long int ll;

int dp[100001];

const int INF = 987654321;
int N, K;

int ans = 987654321;

void go() {
	queue<int> Q;

	Q.push(N);
	dp[N] = 0;

	while (!Q.empty()) {
		auto cur = Q.front();
		Q.pop();

		if (cur == K) {
			ans = dp[cur];
			return;
		}
		if (cur * 2 < 100001 && dp[cur * 2] > dp[cur]) {
			dp[cur * 2] = dp[cur];
			Q.push(cur * 2);
		}
		if (cur + 1 < 100001 && dp[cur + 1] > dp[cur] + 1) {
			dp[cur + 1] = dp[cur] + 1;
			Q.push(cur + 1);
		}
		if (cur - 1 >= 0 && dp[cur - 1] > dp[cur] + 1) {
			dp[cur - 1] = dp[cur] + 1;
			Q.push(cur - 1);
		}
	}
}
int main() {
	cin >> N >> K;

	for (int i = 0; i < 100001; i++) {
		dp[i] = 1000000;
	}

	go();

	cout << ans << '\n';
	return 0;
}