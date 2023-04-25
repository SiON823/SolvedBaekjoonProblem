#include <iostream>
#include <cstring>

using namespace std;

int N, W;
int dp[1010][1010];
int ev[1010][2];

int Distance(int p1, int p2)
{
	if (p1 == W || p2 == W) return 0;
	if (dp[p1][p2] != -1) return dp[p1][p2];

	int next_ev = max(p1, p2) + 1;
	int Dist1, Dist2;

	if (p1 == 0) Dist1 = abs(ev[next_ev][0] - 1) + abs(ev[next_ev][1] - 1);
	else Dist1 = abs(ev[next_ev][0] - ev[p1][0]) + abs(ev[next_ev][1] - ev[p1][1]);

	if (p2 == 0) Dist2 = abs(ev[next_ev][0] - N) + abs(ev[next_ev][1] - N);
	else Dist2 = abs(ev[next_ev][0] - ev[p2][0]) + abs(ev[next_ev][1] - ev[p2][1]);

	int Result1 = Dist1 + Distance(next_ev, p2);
	int Result2 = Dist2 + Distance(p1, next_ev);
	dp[p1][p2] = min(Result1, Result2);
	return dp[p1][p2];
}

void Route(int p1, int p2)
{
	if (p1 == W || p2 == W) return;

	int next_ev = max(p1, p2) + 1;
	int Dist1, Dist2;

	if (p1 == 0) Dist1 = abs(ev[next_ev][0] - 1) + abs(ev[next_ev][1] - 1);
	else Dist1 = abs(ev[next_ev][0] - ev[p1][0]) + abs(ev[next_ev][1] - ev[p1][1]);

	if (p2 == 0) Dist2 = abs(ev[next_ev][0] - N) + abs(ev[next_ev][1] - N);
	else Dist2 = abs(ev[next_ev][0] - ev[p2][0]) + abs(ev[next_ev][1] - ev[p2][1]);

	if (dp[next_ev][p2] + Dist1 < dp[p1][next_ev] + Dist2)
	{
		cout << 1 << '\n';
		Route(next_ev, p2);
	}
	else
	{
		cout << 2 << '\n';
		Route(p1, next_ev);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);

	cin >> N >> W;
	for (int i = 1; i <= W; i++)
	{
		cin >> ev[i][0] >> ev[i][1];
	}
	memset(dp, -1, sizeof(dp));

	cout << Distance(0, 0) << '\n';

	Route(0, 0);

	return 0;
}