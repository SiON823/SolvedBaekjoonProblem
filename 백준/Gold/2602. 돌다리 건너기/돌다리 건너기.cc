#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <vector>

using namespace std;
typedef long long ll;

int dp[2][101][21];

int main()
{
	string s;
	string bridge[2];

	cin >> s;
	cin >> bridge[0] >> bridge[1];

	int N = bridge[0].size();
	int M = s.size();

	s = " " + s;
	bridge[0] = " " + bridge[0];
	bridge[1] = " " + bridge[1];

	dp[0][0][0] = dp[1][0][0] = 1;

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < 2; k++) {
				if (bridge[k][j] != s[i]) {
					continue;
				}

				for (int l = j - 1; l >= 0; l--) {
					if (bridge[1 - k][l] == s[i - 1]) {
						dp[k][j][i] += dp[1 - k][l][i - 1];
					}
				}
			}
		}
	}

	int res = 0;
	for (int k = 0; k < 2; k++) {
		for (int i = 1; i <= N; i++) {
			res += dp[k][i][M];
		}
	}

	cout << res << "\n";

	return 0;
}
