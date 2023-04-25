#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <array>

using namespace std;

char str1[4001], str2[4001];

int ol[4001][4001] = {0};
int m = 0;

int main() 
{
	scanf("%s", str1);
	scanf("%s", str2);

	for (int i = 0; i < strlen(str1); i++) {
		for (int j = 0; j < strlen(str2); j++) {
			if (str1[i] == str2[j]) {
				if (i == 0 || j == 0) {
					ol[i][j] = 1;
				}
				else {
					ol[i][j] = ol[i - 1][j - 1] + 1;
				}

				if (m < ol[i][j]) m = ol[i][j];
			}
		}
	}

	printf("%d", m);



}