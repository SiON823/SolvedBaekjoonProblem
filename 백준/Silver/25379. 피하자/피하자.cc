#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <numeric>

using namespace std;

typedef long long int ll;


int main() {
	vector<int> arr;
	vector<int> idx1, idx2;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		arr.push_back(x%2);

		if (x % 2 == 0) idx1.push_back(i);
		else idx2.push_back(i);
	}

	int sum1 = accumulate(idx1.begin(), idx1.end(), 0);
	int sum2 = accumulate(idx2.begin(), idx2.end(), 0);

	int size1 = idx1.size();
	int size2 = idx2.size();

	cout << min(-((size1 * (size1 - 1)) / 2) + sum1, -((size2 * (size2 - 1)) / 2) + sum2) << '\n';

	return 0;
}