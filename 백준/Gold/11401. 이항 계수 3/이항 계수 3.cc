#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include<cmath>

using namespace std;
typedef long long int ll;

const ll mod = 1000000007;

ll N, K, A, B, half;

ll solve(int x)
{
	if (x == 0) return 1;

	if (x % 2 == 1) return B * solve(x - 1) % mod;
	else
	{
		half = solve(x / 2);
		return half * half % mod;
	}
}

int main()
{
	cin >> N >> K;
	A = 1;
	for (int i = N; i >= N - K + 1; i--) A = (A * i) % mod;

	B = 1;
	for (int i = 1; i <= K; i++) B = (B * i) % mod;

	B = solve(mod - 2);

	cout << A * B % mod;

}