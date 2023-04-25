#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>

using namespace std;


int b[20];
double p[20];
double dp[17][1 << 16];
int n;

double go(int c, int s, int m)
{
	if (c == 0) return 1.0;
	if (dp[c][s] >= 0.0) return dp[c][s];

	double& ans = dp[c][s];
	ans = 0.0;

	for (int i = 0; i < n; i++) {
		if (s & (1 << i)) continue;
		if (m < b[i]) continue;
		double x = p[i] * go(c - 1, s | (1 << i), m - b[i]);
		double f = (1 - p[i]) * go(c, s | (1 << i), m - b[i]);

		if (ans < x + f) ans = x + f;
	}

	return ans;
}

int main()
{
	int T, c, m;

	cin >> T;

	while (T--) {
		cin >> n >> c >> m;
		for (int i = 0; i < n; i++) {
			cin >> b[i] >> p[i];
			p[i] /= 100.0;
		}
		for (int i = 0; i <= c; i++) {
			for (int j = 0; j < (1 << n); j++) {
				dp[i][j] = -1;
			}
		}
		cout << fixed << setprecision(6) << go(c, 0, m) << '\n';
	}
	return 0;
}