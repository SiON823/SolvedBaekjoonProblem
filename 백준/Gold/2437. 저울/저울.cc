#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int a[1001];

int main(void)
{
	ios_base::sync_with_stdio(0);
	
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> a[i];

	sort(a, a + N);

    //결과값 구하기
    int res = 1;
    for (int i = 0; i < N; i++) {
        if (a[i] > res) {
            break;
        }
        res += a[i];
    }

    //출력
    cout << res;

	return 0;
}