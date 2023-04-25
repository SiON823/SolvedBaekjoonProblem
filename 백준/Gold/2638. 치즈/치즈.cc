#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int N, M;
int map[100][100];
int visit[100][100];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

vector<pair<pair<int, int>, bool>> V;
vector<pair<int, int>> Cheese;
queue<pair<int, int>> NQ;

void FindMeltCheese() {
    Cheese.clear();
    for (int i = 0; i < V.size(); i++) {
        if (V[i].second == true) continue;

        int x = V[i].first.first;
        int y = V[i].first.second;
        int cnt = 0;

        for (int j = 0; j < 4; j++) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (map[nx][ny] == 0 && visit[nx][ny] == 1) cnt++;
        }

        if (cnt >= 2) {
            Cheese.push_back({ x, y });
            V[i].second = true;
        }
    }
}

void Melting_Cheese() {
    for (int i = 0; i < Cheese.size(); i++) {
        int x = Cheese[i].first;
        int y = Cheese[i].second;
        map[x][y] = 0;
        NQ.push({ x, y });
    }
}

void AirInit() {
    while (NQ.empty() == 0) {
        int x = NQ.front().first;
        int y = NQ.front().second;
        NQ.pop();

        visit[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (visit[nx][ny] == 0) {
                visit[nx][ny] = 1;
                NQ.push({ nx, ny });
            }
        }
    }
}

bool clear() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
        {
            if (map[i][j] == 1) return false;
        }
    }
    return true;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) {
                V.push_back({ {i, j}, false });
                visit[i][j] = -1;
            }
        }
    }

    queue<pair<int, int>> Q;
    Q.push({ 0, 0 });
    visit[0][0] = 1;

    while (Q.empty() == 0) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < N && ny < M) {
                if (visit[nx][ny] == 0) {
                    visit[nx][ny] = 1;
                    Q.push({ nx, ny });
                }
            }
        }
    }

    int ans = 0;
    while (!clear()) {
        FindMeltCheese();
        Melting_Cheese();
        AirInit();
        ans++;
    }

    cout << ans << '\n';

    return 0;
}
