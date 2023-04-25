#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

int arr[101];
int sol[501];

int gcd(int a, int b) {
    return a % b ? gcd(b, a % b) : b;
}


int main() {
    int n, include_m, i, count=0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    sort(arr, arr + n);

    include_m = arr[1] - arr[0];
    for (i = 2; i < n; i++)
        include_m = gcd(include_m, arr[i] - arr[i - 1]);

    for (i = 1; i * i <= include_m; i++)
        if (include_m % i == 0) {
            sol[count++] = i;
            if (i != include_m / i) sol[count++] = include_m / i;
        }

    sort(sol, sol + count);
    for (int i = 0; i < count; i++)
        if (sol[i] != 1)
            printf("%d ", sol[i]);

}
