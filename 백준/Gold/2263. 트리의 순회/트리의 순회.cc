#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
typedef long long int ll;

typedef pair<int, int> gilsu;

int inorder[100001];
int postorder[100001];

void go(int start, int end, int start2, int end2) {
    if (postorder[end2] == 0) return;
    if (start > end || start2 > end2) return;

    int index = 0;

    for (int i = start; i <= end; i++) {
        if (inorder[i] == postorder[end2]) {
            index = i;
            break;
        }
    }
    cout << postorder[end2] << ' ';
    go(start, index - 1, start2, start2 + (index - start) - 1 );
    go(index + 1, end, start2 + (index - start), end2 - 1);

    return;
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> inorder[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> postorder[i];
    }

    go(0, N-1, 0, N-1);

    return 0;
}