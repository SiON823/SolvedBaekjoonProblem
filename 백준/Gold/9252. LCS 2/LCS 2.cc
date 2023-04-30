#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

typedef long long int ll;

const int INF = 987654321;

int dp[1001][1001];

int main() {
    string X, Y;
	string temp1, temp2;
	cin >> temp1;
	cin >> temp2;

	X = ' ' + temp1;
	Y = ' ' + temp2;

	for (int i = 1; i < Y.size(); i++) {
		for (int j = 1; j < X.size(); j++) {
			if (X[j] == Y[i]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	string res;
	int col = X.size() - 1;
	int row = Y.size() - 1;

	while (dp[row][col]) {
		if (dp[row][col] == dp[row - 1][col]) row--;
		else if (dp[row][col] == dp[row][col - 1]) col--;
		else {
			res += X[col];
			row--, col--;
		}
	}

	cout << dp[Y.size() - 1][X.size() - 1] << '\n';
	if (res.size() > 0) {
		reverse(res.begin(), res.end());
		cout << res << '\n';
	}
	return 0;
}