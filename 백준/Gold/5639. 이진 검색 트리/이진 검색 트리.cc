#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
typedef long long int ll;

const int INF = 987654321;

vector<int> v;

void go(int node, int bound) {
	int right = node + 1;
	while (right <= bound && v[right] < v[node]) ++right;

	int left = node + 1;
	if (left < right) go(left, right - 1);
	if (right <= bound)go(right, bound);

	cout << v[node] << '\n';
}

int main() {
	int a;
	while (cin >> a) v.push_back(a);

	int size = v.size();
	go(0, size - 1);
	return 0;
}