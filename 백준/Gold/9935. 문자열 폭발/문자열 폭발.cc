#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <numeric>

using namespace std;
typedef long long int ll;

string S, Bomb;
string ans = "";

int main() {
	cin >> S;
	cin >> Bomb;

	for (int i = 0; i < S.length(); i++) {
		ans += S[i];
		
		if (ans.length() >= Bomb.length()) {
			bool check = true;
			
			for (int j = 0; j < Bomb.length(); j++) {
				if (ans[ans.length() - Bomb.length() + j] != Bomb[j]) {
					check = false;
					break;
				}
			}

			if (check) ans.erase(ans.end() - Bomb.length(), ans.end());
		}
	}

	if (ans.empty()) cout << "FRULA" << '\n';
	else cout << ans << '\n';

	return 0;

}