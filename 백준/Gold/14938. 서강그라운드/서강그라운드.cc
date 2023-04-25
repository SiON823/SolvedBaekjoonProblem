#include <iostream>
#include <algorithm>

using namespace std;
int N, M, R, a, b, c, result = 0;
const int INF = 0xFFFFFF;

int item[101];
int dp[101][101];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> R;

	for (int i = 1; i <= N; i++)
		cin >> item[i];

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (i != j)	dp[i][j] = INF;

	for (int i = 0; i < R; i++) {
		cin >> a >> b >> c;
		dp[a][b] = c;
		dp[b][a] = c;
	}

	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (dp[i][j] > dp[i][k] + dp[k][j])
					dp[i][j] = dp[i][k] + dp[k][j];

	for (int i = 1; i <= N; i++) {
		int temp = 0;
		for (int j = 1; j <= N; j++)
			if (dp[i][j] <= M)
				temp += item[j];
		result = max(result, temp);
	}
	cout << result;
	return 0;
}