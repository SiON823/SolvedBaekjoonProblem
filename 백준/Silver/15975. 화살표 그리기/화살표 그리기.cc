#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>

using namespace std;
typedef pair<int, int> pii;

int n;

int main() {
	cin >> n;
	vector<vector<long long>> arr(100001);

	long long a, b, ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		arr[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		if (arr[i].size() <= 1) continue;

		sort(arr[i].begin(), arr[i].end());

		ans += arr[i][1] - arr[i][0];

		for (int j = 1; j < arr[i].size() - 1; j++) {
			long long tmp = min(arr[i][j] - arr[i][j - 1], arr[i][j + 1] - arr[i][j]);
			ans += tmp;
		}
		ans += arr[i][arr[i].size() - 1] - arr[i][arr[i].size() - 2];
	}
	cout << ans;
}