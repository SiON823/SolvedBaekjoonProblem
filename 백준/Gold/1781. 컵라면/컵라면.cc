#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long int ll;

vector< pair<int, int> > x;

priority_queue< int, vector<int>, greater<int> > Q;

int main() {
    int N;
    cin >> N;

    x.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> x[i].first >> x[i].second;
    }

    sort(x.begin(), x.end());

    for (int i = 0; i < N; i++) {
        pair<int, int> p = x[i];
        if (Q.size() == p.first) {
            if (Q.top() < p.second) {
                Q.pop();
                Q.push(p.second);
            }
        }
        else {
            Q.push(p.second);
        }
    }
    int ans = 0;
    while (!Q.empty()) {
        ans += Q.top();
        Q.pop();
    }

    cout << ans << '\n';
    
    return 0;
}