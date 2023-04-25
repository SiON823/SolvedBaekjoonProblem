#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>

using namespace std;

typedef long long int ll;

const ll mod = 1000000007;

int dp[1001][1001];

int main() {
    string A, B;

    cin >> A;
    cin >> B;

    int lena = A.length();
    int lenb = B.length();

    for (int i = 1; i <= lena; i++) {
        for (int j = 1; j <= lenb; j++) {
            if (A[i - 1] == B[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << dp[lena][lenb] << '\n';

    return 0;
}