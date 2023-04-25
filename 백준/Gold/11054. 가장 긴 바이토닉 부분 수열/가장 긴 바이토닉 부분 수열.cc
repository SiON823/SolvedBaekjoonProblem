#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <numeric>

using namespace std;
typedef long long int ll;

int N;
int arr[1001];
int L_dp[1001];
int R_dp[1001];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];

	for (int i = 1; i <= N; i++) {
		L_dp[i] = 1;
		for (int j = 1; j <= i; j++) {
			if (arr[j] < arr[i] && L_dp[i] < L_dp[j] + 1) {
				L_dp[i] = L_dp[j] + 1;
			}
		}
	}
	for (int i = N; i >= 1; i--) {
		R_dp[i] = 1;
		for (int j = N; j >= i; j--) {
			if (arr[j] < arr[i] && R_dp[i] < R_dp[j] + 1) {
				R_dp[i] = R_dp[j] + 1;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= N; i++) {
		ans = max(ans, L_dp[i] + R_dp[i] - 1);
	}
	cout << ans << '\n';

	return 0;

}