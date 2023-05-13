#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string x;
    cin >> x;

    string num = "";
    int ans = 0;
    bool check = false;

    for (int i = 0; i <= x.size(); i++) {
        if (x[i] == '-' || x[i] == '+' || i == x.size()) {
            if (check) {
                ans -= stoi(num);
                num = "";
            }
            else {
                ans += stoi(num);
                num = "";
            }
        }
        else {
            num += x[i];
        }
        if (x[i] == '-') {
            check = true;
        }
    }

    cout << ans << '\n';

    return 0;
}