#include <iostream>
#include <deque>
#include <string>

using namespace std;
int eat[20001] = { 0 };

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;
    string x;
    cin >> x;
    int ans = 0;
    
    for (int i = 0; i < x.length(); i++) {
        if (x[i] == 'P') {
            int j = max(0, i - K);
            while (j < min(N, i+K+1)) {
                if (x[j] == 'H' && eat[j] == 0) {
                    eat[j] = 1;
                    ans++;
                    break;
                }
                j++;
            }
        }
    }
    cout << ans << '\n';

    return 0;
}
