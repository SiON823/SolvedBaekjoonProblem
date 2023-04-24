#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <array>

using namespace std;

int T, N, K, X, Y, W;
int D[1002];
int pre[1001][1001];
int minT[1002];

int mintime(int W)
{
	if (minT[W] >= 0) return minT[W];
	int max = 0;
	int time;
	for (int i = 1; i <= N; i++) {
		if (pre[i][W] == 1) {
			if (minT[i] >= 0) time = minT[i];
			else time = mintime(i);

			if (time > max) max = time;
		}
	}
	return minT[W] = max + D[W];
}


int main() 
{
	int temp = 0;
	int temp2 = 0;
	
	scanf("%d", &T);

	for (int tr = 0; tr < T; tr++) {
		scanf("%d %d", &N, &K);

		memset(D, 0, sizeof(D));
		memset(minT, -1, sizeof(minT));
		memset(pre, 0, sizeof(pre));

		for (int i = 1; i <= N; i++) {
			scanf("%d", &D[i]);
		}
		for (int i = 0; i < K; i++) {
			scanf("%d %d", &temp, &temp2);

			pre[temp][temp2] = 1;

		}
		scanf("%d", &W);
		printf("%d\n", mintime(W));
	}
}