#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

typedef long long int ll;

ll dp[2001][2001];
int m;

vector<int> Luca(ll val, int mod) {
    vector<int> ret;
    while (val > 0) {
        int re = val % mod;
        ret.push_back(re);
        val /= mod;
    }
    return ret;
}

ll c(int n, int r) {
    if (n < r) return 0;

    if (n / 2 < r) r = n - r;

    ll& ret = dp[n][r];
    if (ret != -1) return ret;

    if (r == 0) return ret = 1;
    else if (r == 1) return ret = n;

    return ret = (c(n - 1, r - 1) + c(n - 1, r)) % m;
}

int main() {
    ios_base::sync_with_stdio(false);

    memset(dp, -1, sizeof(dp));

    ll n, k, res = 1;

    cin >> n >> k >> m;

    vector<int> lucaN, lucaK;
    lucaN = Luca(n, m);
    lucaK = Luca(k, m);

    int minIdx = min(lucaN.size(), lucaK.size());
    for (int i = 0; i < minIdx; ++i) {
        int n = lucaN[i];
        int r = lucaK[i];

        res = res * c(n, r);
        res %= m;
    }

    cout << res << "\n";

    return 0;
}