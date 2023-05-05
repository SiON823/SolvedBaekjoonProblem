#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <numeric>
#include <queue>

using namespace std;
typedef unsigned long long int ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string x;
	cin >> x;

	queue<int> A;
	queue<int> B;

	int ans = 0;

	for (int i = 0; i < x.size(); i++) {
		if (x[i] == 'A') A.push(i);
		else if (x[i] == 'B') B.push(i);
		else if (x[i] == 'C') {
			B.pop();
			ans += 1;
		}
	}
	while (A.size() != 0 && B.size() != 0) {
		if (A.front() < B.front()) {
			A.pop();
			B.pop();
			ans += 1;
		}
		else {
			B.pop();
			
		}
	}

	cout << ans << '\n';
	
	return 0;
}