#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>

using namespace std;

typedef long long int ll;

typedef vector<vector<int>> matrix;

int N;

matrix operator * (const matrix& a, const matrix& b) {
    matrix res(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
            res[i][j] %= 1000;
        }
    }
    return res;
}

int main() {
    ll b;

    cin >> N >> b;

    matrix ans(N, vector<int>(N));
    matrix a(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
        ans[i][i] = 1; // I 만들어놓기
    }

    while (b > 0) {
        if (b % 2 == 1) {
            ans = ans * a;
        }
        a = a * a;
        b /= 2;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
