#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>

using namespace std;

bool d[101][101];

bool go(string& p, string& s)
{
	int n = p.length();
	int m = s.length();

	for (int i = n; i >= 0; i--) {
		for (int j = m; j >= 0; j--) {
			if (i == n && j == m) {
				d[i][j] = true;
			}
			else if (p[i] == s[j]) {
				d[i][j] = d[i + 1][j + 1];
			}
			else if (p[i] == '*') {
				d[i][j] = false;
				for (int k = j; k <= m; k++) {
					if (d[i + 1][k]) {
						d[i][j] = true;
						break;
					}
				}
			}
			else d[i][j] = false;
		}
	}
	return d[0][0];
}

int main()
{
	string p;
	cin >> p;
	int n;
	cin >> n;

	while (n--) {
		string s;
		cin >> s;
		if (go(p, s)) cout << s << '\n';
	}

	return 0;
}