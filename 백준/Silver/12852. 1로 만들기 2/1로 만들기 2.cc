#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int INF = 123456789;

int dp[1000001] = { 0 };
int trace[1000001] = { 0 };

int go(int x) {
    if (x == 1) return 0;
    if (dp[x] != 0) return dp[x];

    int& ret = dp[x];
    ret = INF;

    if (x % 3 == 0) {
        int tmp = go(x / 3) + 1;
        if (ret > tmp) {
            ret = tmp;
            trace[x] = x / 3;
        }
    }
    if (x % 2 == 0) {
        int tmp = go(x / 2) + 1;
        if (ret > tmp) {
            ret = tmp;
            trace[x] = x / 2;
        }
    }
    int tmp = go(x - 1) + 1;
    if (ret > tmp) {
        ret = tmp;
        trace[x] = x - 1;
    }

    return ret;
}

int main() {
    int N;
    cin >> N;
    memset(dp, 0, sizeof(dp));

    go(N);

    vector<int> ans;
    int cur = N;
    ans.push_back(cur);

    while (cur != 1) {
        cur = trace[cur];
        ans.push_back(cur);
    }

    cout << ans.size() - 1 << '\n';
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';

    return 0;
}