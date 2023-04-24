#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long int ll;

char arr[10][10];
int len[10];
int alpha[26];

bool f(int a, int b) { return a > b; }

int main(void) {
    int n;
    int cal;
    int res = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        len[i] = strlen(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        cal = 1;
        for (int j = len[i] - 1; j >= 0; j--) {
            alpha[arr[i][j] - 'A'] += cal;
            cal *= 10;
        }
    }

    sort(alpha, alpha + 26, f);

    for (int i = 0; i < 10; i++) {
        res += alpha[i] * (9 - i);
    }

    printf("%d\n", res);
}