#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>

using namespace std;

typedef long long int ll;

int dp[1001];
int arr[1001];
int N;

int go(int x) {
    int& res = dp[x+1];
    if (res != -1) return res;

    res = 1;

    for (int i = x+1; i < N; i++) {
        if (x == -1 || arr[x] < arr[i]) {
            res = max(res, go(i) + 1);
        }
    }
    
    return res;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    memset(dp, -1, sizeof(dp));

    int res = 1;
    for (int i = 0; i < N; i++) {
        res = max(res, go(i));
    }

    cout << res;
}
