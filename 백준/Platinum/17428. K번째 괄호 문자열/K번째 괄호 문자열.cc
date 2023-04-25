#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;
typedef long long ll;


int N;
ll k, dp[51][51];

ll go(int now, int sum) {
    if (now == N) return !sum;
    ll& x = dp[now][sum];
    if (x != -1) return x;
    x = go(now + 1, sum + 1);
    if (sum) x += go(now + 1, sum - 1);
    return x;
}

void gogo(int now, int sum, ll k) {
    if (now == N) return;
    if (go(now+1, sum+1) <= k) {
        printf(")");
        gogo(now + 1, sum - 1, k - go(now+1, sum+1));
    }
    else {
        printf("(");
        gogo(now + 1, sum + 1, k);
    }
}

int main() {
    scanf("%d %lld", &N, &k);

    memset(dp, -1, sizeof(dp));
    go(0, 0);

    if (dp[0][0] <= k) {
        return !puts("-1");
    }
    else gogo(0, 0, k);

    return 0;
}