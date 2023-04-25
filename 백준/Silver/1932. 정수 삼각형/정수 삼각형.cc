#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
typedef long long int ll;

const int INF = 987654321;

int N;
int arr[500][500];
int dp[500][500];

int main() {
	cin >> N;
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = N - 1; i >= 1; i--) {
		for (int j = 0; j < i; j++) {
			arr[i - 1][j] += max(arr[i][j], arr[i][j + 1]);
		}
	}

	cout << arr[0][0];
}