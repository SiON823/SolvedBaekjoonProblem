#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 1001;
const int INF = 0xFFFFFF;

vector<pair<int, int>> map[MAX];
int dp[MAX], ans[MAX];


void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q; //거리, 노드
    Q.push({ 0, start });
    dp[start] = 0;

    while (!Q.empty()) {
        int cost = Q.top().first;
        int cur = Q.top().second;
        Q.pop();

        for (int i = 0; i < map[cur].size(); i++) {
            int next = map[cur][i].first;
            int nCost = map[cur][i].second;

            if (cost + nCost < dp[next]) {
                dp[next] = cost + nCost;
                Q.push({ cost + nCost, next });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M, x;
    cin >> N >> M >> x;

    for (int i = 1; i <= N; i++) {
        dp[i] = INF;
    }

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        map[a].push_back({ b, c });
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dp[j] = INF;
        }
        dijkstra(i);
        ans[i] = dp[x];
    }

    for (int i = 1; i <= N; i++) dp[i] = INF;

    dijkstra(x);

    for (int i = 1; i <= N; i++) {
        ans[i] += dp[i];
    }

    cout << *max_element(ans + 1, ans + N + 1);

    return 0;
}