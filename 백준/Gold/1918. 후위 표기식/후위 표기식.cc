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

int main() {
	stack<char> S;
	string input;
	cin >> input;
	string ans = "";

	for (int i = 0; i < input.size(); i++) {
		char x = input[i];

		if (isalpha(x)) ans += x;
		else if (x == '(') S.push(x);
		else if (x == '*' || x == '/') {
			while (!S.empty() && (S.top() == '*' || S.top() == '/')) {
				ans += S.top();
				S.pop();
			}

			S.push(x);
		}
		else if (x == '+' || x == '-') {
			while (!S.empty() && S.top() != '(') {
				ans += S.top();
				S.pop();
			}
			S.push(x);
		}
		else if (x == ')') {
			while (!S.empty() && S.top() != '(') {
				ans += S.top();
				S.pop();
			}
			S.pop();
		}
	}

	while (!S.empty()) {
		ans += S.top();
		S.pop();
	}

	cout << ans << '\n';
	return 0;
}