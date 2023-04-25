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
ll n;

typedef vector<vector<ll>> matrix;

matrix operator * (const matrix& a, const matrix& b) {
    matrix res(2, vector<ll>(2));
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
            res[i][j] %= mod;
        }
    }
    return res;
}

int main() {
    cin >> n;

    if (n == 0) {
        cout << 0 << '\n';
        return 0;
    }
    if (n == 1) {
        cout << 1 << '\n';
        return 0;
    }
    if (n == 2) {
        cout << 1 << '\n';
        return 0;
    }

    n = n - 1;

    matrix ans(2, vector<ll>(2));
    matrix a(2, vector<ll>(2));

    a[0][0] = 0;
    a[0][1] = 1;
    a[1][0] = 1;
    a[1][1] = 1;

    ans[0][0] = 1;
    ans[1][1] = 1;
    ans[0][1] = 0;
    ans[1][0] = 0;

    while (n > 0) {
        if (n % 2 == 1) {
            ans = ans * a;
        }
        a = a * a;
        n /= 2;
    }


    cout << ans[1][1] << '\n';

    return 0;
}