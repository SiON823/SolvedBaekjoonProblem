#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int arr[301][301];
int sum[301][301];

int main(void)
{
	ios_base::sync_with_stdio(0);
	
	int N, M, K;
	cin >> N >> M;

	memset(sum, 0, sizeof(sum));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j-1] + arr[i][j];

		}
	}

	cin >> K;

	for (int t = 0; t < K; t++) {
		int i, j, x, y;
		cin >> i >> j >> x >> y;
		cout << sum[x][y] - sum[i - 1][y] - sum[x][j - 1] + sum[i - 1][j - 1] << '\n';
	}

	
	return 0;
}