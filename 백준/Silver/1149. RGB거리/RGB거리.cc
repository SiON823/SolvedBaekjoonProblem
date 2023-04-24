#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arr[4][1001] = {0};
int srr[4][1001] = {0};

int min(int a, int b) {
	if (a < b) return a;
	else return b;
}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i < n+1; i++) {
		scanf("%d %d %d", &arr[1][i], &arr[2][i], &arr[3][i]);
	}
	srr[1][1] = arr[1][1];
	srr[2][1] = arr[2][1];
	srr[3][1] = arr[3][1];
	for (int i = 2; i < n+1; i++) {
		srr[1][i] = min(srr[2][i - 1], srr[3][i - 1]) + arr[1][i];
		srr[2][i] = min(srr[3][i - 1], srr[1][i - 1]) + arr[2][i];
		srr[3][i] = min(srr[1][i - 1], srr[2][i - 1]) + arr[3][i];
	}

	printf("%d", min(min(srr[1][n], srr[2][n]), srr[3][n]));


}