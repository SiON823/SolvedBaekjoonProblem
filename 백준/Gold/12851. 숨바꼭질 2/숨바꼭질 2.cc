// 숨바꼭질 3 코드로 날먹 감사합니다!!!
// 아 안되네 ㅠㅠ

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;
typedef long long int ll;

int N, K, ans, cnt;
bool visit[200001];


void go() {
	queue<pair<int, int>> Q;

	Q.push({N, 0});
	visit[N] = true;

	while (!Q.empty()) {
		int cur = Q.front().first;
		int time = Q.front().second;

		Q.pop();
		visit[cur] = true;

		if (cnt && cur == K && ans == time) cnt++;

		if (!cnt && cur == K) {
			ans = time;
			cnt++;
		}

		if (cur * 2 <= 100000 && !visit[cur * 2]) Q.push({ cur * 2, time + 1 });
		if (cur + 1 <= 100000 && !visit[cur + 1]) Q.push({ cur + 1, time + 1 });
		if (cur - 1 >= 0 && !visit[cur - 1]) Q.push({ cur - 1, time + 1 });
	}
}
int main() {
	cin >> N >> K;

	go();

	cout << ans << '\n' << cnt << '\n';
	return 0;
}