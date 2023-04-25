#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long int ll;

const int INF = 987654321;

vector<pair<int, int>> gil[1001];
priority_queue<pair<int, int>> Q;
vector<int> dist(1001, INF);

int x, y;

int route[1001];
vector<int> reroute;

void solve() {
    Q.push({ 0,x });
    dist[x] = 0;
    while (!Q.empty()) {
        int cur = Q.top().second;
        int cost = -Q.top().first;
        Q.pop();

        if (dist[cur] < cost) continue;

        for (int i = 0; i < gil[cur].size(); i++) {
            int next = gil[cur][i].first;
            int nCost = gil[cur][i].second + cost;

            if (dist[next] > nCost) {
                route[next] = cur;
                dist[next] = nCost;
                Q.push({ -nCost,next });
            }
        }
    }
}

int main() {
    int N, M;
    int a, b, c;

    cin >> N >> M;

    while (M--) {
        cin >> a >> b >> c;
        gil[a].push_back({ b,c });
    }

    cin >> x >> y;

    solve();

    cout << dist[y] <<'\n';

    int temp = y;
    while (temp) {
        reroute.push_back(temp);
        temp = route[temp];
    }
    cout << reroute.size() << '\n';
    for (int i = reroute.size() - 1; i >= 0; i--) {
        cout << reroute[i] << ' ';
    }
    cout << '\n';

    return 0;
}