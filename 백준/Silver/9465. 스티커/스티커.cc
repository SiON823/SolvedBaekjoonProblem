#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
typedef long long int ll;

const int INF = 987654321;

int arr[100000][2];
int dp[100000][2];
int T,N;

int go(int x, int y) {
	if (x > N - 1) return 0;

	int& res = dp[x][y];
	if (res != -1) return res;

	res = arr[x][y];

	if (y == 0) {
		res = max(res + go(x + 1, 1), res + go(x + 2, 1));
	}
	else {
		res = max(res + go(x + 1, 0), res + go(x + 2, 0));
	}

	return res;
}

int main() {
	cin >> T;
	
	while (T--) {
		memset(dp, -1, sizeof(dp));

		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> arr[i][0];
		}
		for (int i = 0; i < N; i++) {
			cin >> arr[i][1];
		}

		cout << max(go(0, 0), go(0, 1)) << '\n';
	}
}