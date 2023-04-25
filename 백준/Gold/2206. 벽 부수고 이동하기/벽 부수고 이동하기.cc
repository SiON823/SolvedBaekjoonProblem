#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
typedef long long int ll;

struct gilsu {
    int x, y, wall;
};

int N, M;

const int MAX = 1001;

int graph[MAX][MAX];
int res[MAX][MAX][2];  // [0]: 벽을 부수지 않음, [1]: 벽을 부숨

int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

void BFS() {
    queue<gilsu> Q;
    Q.push({ 0, 0, 0 });
    res[0][0][0] = 1;

    while (!Q.empty()) {
        int x = Q.front().x;
        int y = Q.front().y;
        int wall = Q.front().wall;
        Q.pop();

        if (x == N - 1 && y == M - 1) { printf("%d\n", res[x][y][wall]); return; }

        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i];
            int yy = y + dy[i];

            if (xx < 0 || xx >= N || yy < 0 || yy >= M) continue;

            if (graph[xx][yy] == 0 && res[xx][yy][wall] == 0) {
                res[xx][yy][wall] = res[x][y][wall] + 1;
                Q.push({ xx, yy, wall });
            }
            else if (graph[xx][yy] == 1 && wall == 0 && res[xx][yy][wall + 1] == 0) {
                res[xx][yy][wall + 1] = res[x][y][wall] + 1;
                Q.push({ xx, yy, wall + 1 });
            }
        }
    }
    printf("%d\n", -1);
}

int main() {
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%1d", &graph[i][j]);

            res[i][j][0] = 0;
            res[i][j][1] = 0;
        }
    }

    BFS();
}