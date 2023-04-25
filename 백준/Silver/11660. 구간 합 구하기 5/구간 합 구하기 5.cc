#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
typedef long long int ll;

int dp[1025][1025] = { 0 };
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;
    int temp;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> temp;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + temp - dp[i - 1][j - 1];
        }
    }

    int x1, y1, x2, y2;

    for (int i = 0; i < M; i++) {
        int res = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        res = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
        cout << res << '\n';
    }

    return 0;
}