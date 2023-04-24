#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <numeric>

using namespace std;
typedef long long int ll;

const int INF = 0xFFFFFF;

int N, E, A, B, ans;
int dp[802];
vector<pair<int, int>> node[802];

void go(int x) {
    priority_queue<pair<int, int>> Q;
    dp[x] = 0;
    Q.push({0, x});

    while (Q.empty() == 0) {
        int w = -Q.top().first;
        int now = Q.top().second;
        Q.pop();

        for (int i = 0; i < node[now].size(); i++) {
            int Next = node[now][i].first;
            int nw = node[now][i].second;

            if (dp[Next] > w + nw) {
                dp[Next] = w + nw;
                Q.push({ -dp[Next], Next });
            }
        }
    }
}

int main()
{
    cin >> N >> E;
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        node[a].push_back(make_pair(b, c));
        node[b].push_back(make_pair(a, c));
    }
    cin >> A >> B;

    bool check1, check2;
    check1 = check2 = true;

    fill(&dp[0], &dp[N + 1], INF);
    go(1);

    int p1 = dp[A];
    int p2 = dp[B];
    if (p1 == INF) check1 = false;
    if (p2 == INF) check2 = false;

    fill(&dp[0], &dp[N + 1], INF);
    go(A);

    if (check1 == true) p1 = p1 + dp[B];
    if (check2 == true) p2 = p2 + dp[B];

    fill(&dp[0], &dp[N + 1], INF);
    go(B);

    if (check1 == true) p1 = p1 + dp[N];

    fill(&dp[0], &dp[N + 1], INF);
    go(A);

    if (check2 == true) p2 = p2 + dp[N];

    if (check1 == false && check2 == false) ans = -1;
    else ans = min(p1, p2);

    if (ans >= INF) ans = -1;

    cout << ans << '\n';

    return 0;
}

