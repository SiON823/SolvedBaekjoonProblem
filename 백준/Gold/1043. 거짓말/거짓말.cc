#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 0xFFFFFF;
int parent[51];

int find_parent(int x) {
    if (parent[x] != x)
        return parent[x] = find_parent(parent[x]);
    else
        return parent[x];
}
void merge(int a, int b) {
    int x = find_parent(a);
    int y = find_parent(b);

    if (x != y) {
        if (x < y)
            parent[y] = x;
        else
            parent[x] = y;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, M;
    cin >> N >> M;

    int know;
    cin >> know;

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < know; i++) {
        int a;
        cin >> a;
        parent[a] = 0;
    }
    /*
    for (int i = 0; i < N; i++) {
        cout << parent[i];
    }
    */

    int party[51][51] = { 0 };
    int partynum[51] = { 0 };

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        partynum[i] = a;
        party[i][0] = b;

        for (int j = 1; j < a; j++) {
            int c;
            cin >> c;
            party[i][j] = c;
            merge(b, c);
        }
    }

    int ans = M;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < partynum[i]; j++) {
            if (find_parent(parent[party[i][j]]) == 0) {
                ans--;
                break;
            }
        }
    }

    cout << ans;

    return 0;
}