#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

int N, C;
int arr[200000];

bool possible(int dist)
{
    int cnt = 1;
    int prev = arr[0];

    for (int i = 1; i < N; i++) {
        if (arr[i] - prev >= dist) {
            cnt++;
            prev = arr[i];
        }
    }

    if (cnt >= C) return true;
    return false;
}

int main() 
{
	scanf("%d %d", &N, &C);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    sort(arr, arr + N);

    int low = 1, high = arr[N - 1] - arr[0];
    int result = 0;
    while (low <= high){
        int mid = (low + high) / 2;
        if (possible(mid)){
            result = max(result, mid);
            low = mid + 1;
        }
        else high = mid - 1;
    }
    printf("%d", result);
}