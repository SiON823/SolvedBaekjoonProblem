#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

int a[10];
bool d[5001][5001];
int n, m;

void go(int i, int j) {
	if (i > n) return;
	if (d[i][j]) return;
	d[i][j] = true;

	for (int k = 0; k < m; k++) {
		go(i+j+a[k], j + a[k]);
	}
}

int main()
{
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		
		for (int i = 0; i < m; i++) cin >> a[i];

		memset(d, false, sizeof(d));

		go(0, 0);

		int ans = -1;
		for (int i = 1; i <= n; i++) {
			if (d[n][i]) ans = i;
		}

		cout << ans << '\n';
	}

	return 0;
}