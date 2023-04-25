#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>

using namespace std;

typedef long long int ll;

const ll mod = 1000000007;

int arr[8];
bool visited[8];
vector<int> res;
int N, M;

void DFS(int num, int x) {
    if (x == M) {
        for (int i = 0; i < M; i++) {
            cout << res[i] << " ";
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;

        if (arr[i] > num) {
            visited[i] = true;
            res.push_back(arr[i]);
            DFS(arr[i], x + 1);
            res.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);

    memset(visited, false, sizeof(visited));
    DFS(0, 0);

    return 0;
}