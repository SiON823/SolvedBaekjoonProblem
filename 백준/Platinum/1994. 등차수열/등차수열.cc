#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

int N;
int A[2001] = { 0 };
int D[2001][2001] = { 0 };


int check(int i, int j) {
	if (i > j) return 0;
	else if (i == j) return 1;

	if (D[i][j] != 0) return D[i][j];

	int diff = A[j] - A[i];
	int next = A[j] + diff;
	int p = lower_bound(A, A + N, next) - A;

	if (A[p] == next) {
		D[i][j] = 1 + check(j, p);
		return D[i][j];
	}
	else {
		D[i][j] = 2;
		return D[i][j];
	}
}

int main() 
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	sort(A, A + N);

	int ans = 1;
	int cnt = 1;

	for (int i = 1; i < N; i++) {
		if (A[i] == A[i - 1]) {
			cnt++;
			ans = max(cnt, ans);
		}
		else {
			cnt = 1;
		}
	}

	for (int i = 0; i < N-1; i++) {
		for (int j = i+1; j < N; j++) {
			int x = check(i, j);
			ans = max(x, ans);
		}
	}

	printf("%d", ans);
}