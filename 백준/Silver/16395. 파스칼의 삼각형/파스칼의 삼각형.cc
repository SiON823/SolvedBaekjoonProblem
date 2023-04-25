#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int N, K;

int com[31][31];

int main(void)
{
	ios_base::sync_with_stdio(0);
	
	cin >> N >> K;

	N = N - 1;
	K = K - 1;

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) com[i][j] = 1;
			else com[i][j] = com[i - 1][j - 1] + com[i - 1][j];
		}
	}

	cout << com[N][K];
}