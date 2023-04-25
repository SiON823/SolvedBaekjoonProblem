#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <vector>

using namespace std;
typedef long long ll;

const int MAX = 1132500;
bitset<MAX + 1> d[151];
int score[160][160];

int main()
{
	int n, k;

	scanf("%d", &n);
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

	scanf("%d", &k);
	
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		int acc = 0;
		for (int j = i; j <= n; j++) {
			sum += a[j];
			acc += sum;
			score[i][j] = acc;
		}
	}

	if (k > score[1][n]) {
		printf("%d\n", k);
		return 0;
	}
	else {
		d[0].set(0, 1);
		for (int i = 1; i <= n; i++) {
			d[i].set(score[1][i], 1);
			for (int j = 0; j < i; j++) {
				d[i] |= d[j] << score[j + 2][i];
			}
		}
	}

	while (true) {
		if (d[n].test(k) == 0) {
			printf("%d\n", k);
			break;
		}
		k += 1;
	}
	return 0;
}
