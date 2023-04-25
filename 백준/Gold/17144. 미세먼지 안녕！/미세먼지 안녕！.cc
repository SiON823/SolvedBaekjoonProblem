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

int R, C, T;

int map[51][51];
int mapadd[51][51];

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

int airup, airdown;
int ans = 0;

void f1() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			int temp = map[i][j] / 5;
			int cnt = 0;

			if (map[i][j] == 0 || map[i][j] == -1) continue;

			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
				if (map[nx][ny] == -1) continue;

				mapadd[nx][ny] += temp;
				cnt++;
			}
			map[i][j] -= (cnt * temp);
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			map[i][j] += mapadd[i][j];
			mapadd[i][j] = 0;
		}
	}
}

void f2() {
	ans -= map[airup - 1][0];
	ans -= map[airdown + 1][0];

	for (int i = airup - 1; i > 0; i--) map[i][0] = map[i - 1][0];
	for (int i = 0; i < C - 1; i++) map[0][i] = map[0][i + 1];
	for (int i = 1; i <= airup; i++) map[i - 1][C - 1] = map[i][C - 1];
	for (int i = C - 1; i > 1; i--) map[airup][i] = map[airup][i - 1];

	map[airup][1] = 0;

	for (int i = airdown + 1; i < R - 1; i++) map[i][0] = map[i + 1][0];
	for (int i = 0; i < C - 1; i++) map[R - 1][i] = map[R - 1][i + 1];
	for (int i = R - 1; i >= airdown; i--)map[i][C - 1] = map[i - 1][C - 1];
	for (int i = C - 1; i > 1; i--) map[airdown][i] = map[airdown][i - 1];

	map[airdown][1] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> R >> C >> T;
	bool check = false;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				if (!check) {
					airup = i;
					check = true;
				}
				else {
					airdown = i;
				}
			}
			else ans += map[i][j];
		}
	}

	while (T--) {
		f1();
		f2();
	}
	cout << ans << '\n';

	return 0;
}