#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

typedef long long int ll;

const int MOD = 1e9;

ll dp[10][101][1024];
int N;

ll go(int num, int digit, int bit) {
    if (dp[num][digit][bit] != 0) return dp[num][digit][bit];
    if (digit == N) {
        if (bit == 1023) return 1;
        else return 0;
    }
    int tmp = 0;
    if (num < 9) {
        int des = num + 1;
        tmp += go(des, digit + 1, (bit | 1 << (des)));
    }
    if (num > 0) {
        int des = num - 1;
        tmp += go(des, digit + 1, (bit | 1 << (des)));
    }
    tmp %= MOD;
    return dp[num][digit][bit] = tmp;
}

int main() {
    cin >> N;
    int ans = 0;
    for (int i = 1; i <= 9; i++) {
        ans += go(i, 1, 1 << i);
        ans %= MOD;
    }
    cout << ans;

    return 0;
}