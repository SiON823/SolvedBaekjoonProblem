#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>
#include <cmath>
#include <map>

using namespace std;

typedef long long int ll;
typedef pair<int, int> pos;

const int INF = 10000000;

int N, M;
int ans = INF;

bool selected[13];
vector<pos> house;
vector<pos> chi;
vector<pos> sel;

int D(pos a, pos b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}


void finddist() {
    int res = 0;
    for (int i = 0; i < house.size(); i++) {
        int mind = INF;
        for (int j = 0; j < sel.size(); j++) {
            mind = min(mind, D(house[i], sel[j]));
        }
        res += mind;
    }
    ans = min(ans, res);
}

void solve(int x, int m) {
    if (m == M) finddist();

    for (int i = x; i < chi.size(); i++) {
        if (selected[i] == true)
            continue;

        selected[i] = true;
        sel.push_back(chi[i]);
        solve(i, m + 1);
        selected[i] = false;
        sel.pop_back();
    }
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int tmp;
            cin >> tmp;

            if (tmp == 1)
                house.push_back({ i, j });
            else if (tmp == 2)
                chi.push_back({ i, j });
        }
    }
    solve(0, 0);
    cout << ans << '\n';
    return 0;
}

