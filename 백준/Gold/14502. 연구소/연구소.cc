#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int M, N;
int ans = 0;
int map[8][8];
int temp[8][8];

void coffee(int(*a)[8], int(*b)[8]) {
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) a[i][j] = b[i][j];
}

void spread() {
    int after[8][8];
    coffee(after, temp);
    queue<pair<int, int>> Q;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (after[i][j] == 2)
                Q.push({i, j});

    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                if (after[nx][ny] == 0) {
                    after[nx][ny] = 2;
                    Q.push({nx, ny});
                }
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (after[i][j] == 0)
                cnt += 1;
        }
    }
    ans = max(ans, cnt);
}

void wall(int cnt) {
    if (cnt == 3) {
        spread();
        return;
    }
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (temp[i][j] == 0) {
                temp[i][j] = 1;
                wall(cnt + 1);
                temp[i][j] = 0;
            }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> map[i][j];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0) {
                coffee(temp, map);
                temp[i][j] = 1;
                wall(1);
                temp[i][j] = 0;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
