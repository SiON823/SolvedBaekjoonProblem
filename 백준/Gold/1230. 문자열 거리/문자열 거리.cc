#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;
typedef long long ll;

#define INF 1000

short dp[1001][1001][2];
short min(short a, short b) { return a < b ? a : b; }

int main() 
{
	char O[1004], N[1004];
    fgets(O, sizeof(O), stdin);
    fgets(N, sizeof(N), stdin);

	int lenO = strlen(O);
	int lenN = strlen(N);
	if (lenO > lenN) { printf("-1"); return 0; }
	
	dp[0][0][0] = 0;
	dp[0][0][1] = INF;
	for (int i = 1; i <= lenN; i++) dp[0][i][0] = INF, dp[0][i][1] = 1;

	for (int i = 0; i < lenO; i++) {
		for (int j = 0; j <= i; j++) dp[i + 1][j][0] = dp[i + 1][j][1] = INF;
		for (int j = i; j < lenN; j++) {
			if (O[i] == N[j]) dp[i + 1][j + 1][0] = min(dp[i][j][0], dp[i][j][1]);
			else dp[i + 1][j + 1][0] = INF;

			dp[i + 1][j + 1][1] = min(dp[i + 1][j][0] + 1, dp[i + 1][j][1]);
		}
	}

	int result = min(dp[lenO][lenN][0], dp[lenO][lenN][1]);

	printf("%d", (result >= INF) ? -1:result );
	

	return 0;
}
