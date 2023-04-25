#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>

using namespace std;

typedef long long int ll;
typedef pair<int, int> f;
vector< pair<int, int> > flower;

int md(int month, int date) {
    return 100 * month + date;
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

bool cmp2(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first > b.first;
    return a.second > b.second;
}

int main() {
    int N;
    cin >> N;

    flower.resize(N);

    for (int i = 0; i < N; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        flower[i] = { md(a, b), md(c, d)};
    }

    sort(flower.begin(), flower.end(), cmp2);
    if (md(12, 1) > flower[0].second) { cout << 0 << "\n"; return 0; }
    sort(flower.begin(), flower.end(), cmp);
    if (md(3, 1) < flower[0].first) { cout << 0 << "\n"; return 0; }


    int now = 0;
    for (int i = 1; i < N; i++) {
        f temp = flower[i];
        if (temp.first <= md(3, 1))
            if (temp.second > flower[now].second)
                now = i;
    }

    int ans = 1;

    while (true) {
        if (flower[now].second > md(11, 30)) break;

        f last = { 1, 1 };
        int lastidx = -1;
        for (int i = now + 1; i < N; i++) {
            f temp = flower[i];
            if (temp.first <= flower[now].second) {
                if (temp.second > last.second) {
                    last = temp;
                    lastidx = i;
                }
            }
        }

        now = lastidx;

        if (last.first == 1) { cout << 0 << "\n"; return 0; }
        else ans++;
    }

    cout << ans;
}