#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

vector<pair<char, ll>> info;
vector<bool> ava;

int main() {
    ll N, K;
    ll a, b, c, d;

    cin >> N >> K;
    cin >> a >> b >> c >> d;

    for (ll i = 0; i < N; i++) {
        char w;
        ll q;
        cin >> w >> q;
        info.push_back({ w, q });
        ava.push_back(true);
    }

    while (K--) {
        int idx = 0;
        ll V = a * b * c * d;
        for (int i = 0; i < N; i++) {
            ll x = info[i].first;
            ll y = info[i].second;
            ll temp = 0;

            if (!ava[i]) {
                ava[i] = false;
                continue;
            }

            if (x == 'A') {
                temp = (a + y) * b * c * d;
            }
            else if (x == 'B') {
                temp = a * (b + y) * c * d;
            }
            else if (x == 'C') {
                temp = a * b * (c + y) * d;
            }
            else if (x == 'D') {
                temp = a * b * c * (d + y);
            }

            if (temp > V) {
                idx = i; V = temp;
            }
        }

        ava[idx] = false;
        char p = info[idx].first;
        ll q = info[idx].second;

        if (p == 'A') {
            a += q;
            cout << 'A' << ' ' << q << '\n';
        }
        else if (p == 'B') {
            b += q;
            cout << 'B' << ' ' << q << '\n';
        }
        else if (p == 'C') {
            c += q;
            cout << 'C' << ' ' << q << '\n';
        }
        else if (p == 'D') {
            d += q;
            cout << 'D' << ' ' << q << '\n';
        }
    }



    return 0;
}