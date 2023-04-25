#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

typedef long long int ll;
const int INF = 987654321;

int dp[1001][3];
int N;
int cost[1001][3];

int main() {
	int res = INF;
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> cost[i][0] >> cost[i][1] >> cost[i][2];

	for (int i = 0; i < 3; i++) {
		for (int k = 0; k < 3; k++) {
			if (i == k) dp[1][k] = cost[1][k];
			else dp[1][k] = INF;
		}
		for (int k = 2; k <= N; k++) {
			dp[k][0] = cost[k][0] + min(dp[k - 1][1], dp[k - 1][2]);
			dp[k][1] = cost[k][1] + min(dp[k - 1][0], dp[k - 1][2]);
			dp[k][2] = cost[k][2] + min(dp[k - 1][1], dp[k - 1][0]);
		}
		for (int k = 0; k < 3; k++) {
			if (i != k)
				res = min(res, dp[N][k]);
		}
	}
	cout << res << '\n';
	return 0;
}