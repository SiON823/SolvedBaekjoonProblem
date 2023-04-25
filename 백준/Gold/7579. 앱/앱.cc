#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

typedef long long int ll;
const int INF = 987654321;

int dp[101][10100];
int N, M;
int memory[101];
int cost[101];
int sum = 0;

int go(int n, int k) {
	if (dp[n][k] != -1) return dp[n][k];
	if (k < 0) return -INF;
	if (k == 0) return 0;
	if (n == 1) {
		if (k >= cost[1]) return memory[1];
		else return 0;
	}

	int& res = dp[n][k];

	res = max(go(n - 1, k - cost[n]) + memory[n], go(n - 1, k));
	return res;
}

int main() {
	memset(dp, -1, sizeof(dp));

	cin >> N >> M;
	for (int i = 1; i <= N; i++) cin >> memory[i];
	for (int i = 1; i <= N; i++) {
		cin >> cost[i];
		sum += cost[i];
	}

	for (int i = 1; i <= sum; i++) {
		if (go(N, i) >= M) {
			cout << i << '\n';
			break;
		}
	}

	return 0;
}