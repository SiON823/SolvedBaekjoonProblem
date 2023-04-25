#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

int N, M;
int A[50001] = { 0 };
int D[50001][4] = { 0 };
int sum[50001] = { 0 };

int main() 
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		sum[i] = sum[i - 1] + A[i];
	}
	scanf("%d", &M);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 3; j++) {
			D[i][j] = D[i - 1][j];
			if (i >= M) {
				D[i][j] = max(D[i][j], D[i - M][j - 1] + (sum[i] - sum[i - M]));
			}
		}
	}
	printf("%d", D[N][3]);
	return 0;
}