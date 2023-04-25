#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <numeric>

using namespace std;
typedef long long int ll;

int N;
char map[3072][6144];

void go(int x, int y, int n) {
	if (n == 3) {
		map[x][y] = '*';
		map[x + 1][y - 1] = '*';
		map[x + 1][y + 1] = '*';

		for (int j = y - 2; j <= y + 2; j++) {
			map[x + 2][j] = '*';
		}
		return;
	}

	go(x, y, n / 2);
	go(x + n / 2, y - n / 2, n / 2);
	go(x + n / 2, y + n / 2, n / 2);
}

int main() {
	cin >> N;
	
	fill(&map[0][0], &map[3071][6143], ' ');

	go(0, N - 1, N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N - 1; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}

	return 0;

}