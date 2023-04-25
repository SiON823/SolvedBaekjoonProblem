#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
typedef long long int ll;

const int INF = 10000001;

int map[18][18];
int N;

int rotx[3] = { 0, 1, 1 };
int roty[3] = { 1, 1, 0 };

struct coord {
	int x, y, rot;
};

queue<coord> Q;

void move(int x, int y, int rot) {
	int nx = x + rotx[rot];
	int ny = y + roty[rot];
	int nd = rot;

	if (map[nx][ny] == 0 && nx > 0 && nx <= N && ny > 0 && ny <= N) {
		if (rot == 1) {
			if (map[nx - 1][ny] == 1 || map[nx][ny - 1] == 1) return;
		}
		Q.push({ nx, ny, nd });
	}
	return;
}

int main() {
	int ans = 0;
	
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++){
			cin >> map[i][j];
		}
	}

	Q.push({ 1, 2, 0 });

	while (!Q.empty()) {
		int x = Q.front().x;
		int y = Q.front().y;
		int rot = Q.front().rot;

		Q.pop();

		if (x == N && y == N) ans++;

		for (int j = max(0, rot - 1); j < min(3, rot + 2); j++) {
			move(x, y, j);
		}
	}

	cout << ans << '\n';

	return 0;
}