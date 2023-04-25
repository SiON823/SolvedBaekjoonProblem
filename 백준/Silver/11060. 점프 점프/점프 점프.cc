#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

int N;
int A[1001] = { 0 };
int D[1001] = { 0 };

int main() 
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);

	D[0] = 0;
	for (int i = 1; i < N; i++) {
		D[i] = -1;
		for (int j = 0; j < i; j++) {
			if (D[j] != -1 && i - j <= A[j]) {
				if (D[i] == -1 || D[i] > D[j] + 1) {
					D[i] = D[j] + 1;
				}
			}
		}
	}

	printf("%d", D[N - 1]);
}