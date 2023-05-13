#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <set>


using namespace std;
typedef pair<int, int> pii;

struct cmp {
	bool operator()(pii a, pii b) {
		if (a.second == b.second) {
			return a.first > b.first;
		}
		return a.second > b.second;
	}
};

priority_queue<pii, vector<pii>, cmp> Q;


int main() {
	int N;
	int ans = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		pii x;
		cin >> x.first >> x.second;
		Q.push(x);
	}
	
	int check = 0;

	while (Q.size() > 0) {
		auto x = Q.top();
		if (check <= x.first) {
			ans++;
			check = x.second;
		}
		Q.pop();
	}
	cout << ans <<'\n';
	
	return 0;
}