#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
typedef long long int ll;

const int INF = 987654321;

int V;
vector<pair<int, int>> node[100001];
bool visited[100001];
int endp;
int res;

int DFS(int point, int len) {
	if (visited[point]) return 0;

	visited[point] = true;

	if (res < len) {
		res = len;
		endp = point;
	}

	for (int i = 0; i < node[point].size(); i++) {
		DFS(node[point][i].first, len + node[point][i].second);
	}

	return res;
}

int main() {
	cin >> V;
	memset(visited, false, sizeof(visited));

	for (int i = 0; i < V; i++) {
		int x, y, z;
		cin >> x;

		cin >> y;
		while (y != -1) {
			cin >> z;
			node[x].push_back({ y, z });
			node[y].push_back({ x, z });
			cin >> y;
		}
	}
	res = 0;
	DFS(1, 0);

	memset(visited, false, sizeof(visited));
	res = 0;
	cout << DFS(endp, 0);

}