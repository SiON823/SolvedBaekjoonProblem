#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>

using namespace std;

typedef long long int ll;

ll A, B, C;

ll go(int a, int b) {
    if (b == 1)return a%C;
    
    if (b % 2 != 0) return (((go(a, b / 2) * go(a, b / 2)) % C) * a) % C;
    return (go(a, b / 2) * go(a, b / 2)) % C;
}

int main() {
    cin >> A >> B >> C;

    cout << go(A, B);
}
