#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
typedef long long int ll;

typedef pair<char, char> node;

vector<node> v(26);

void PreOrder(char node) {
    if (node == '.') return;

    cout << node;
    PreOrder(v[node - 'A'].first);
    PreOrder(v[node - 'A'].second);
}

void InOrder(char node) {
    if (node == '.') return;

    InOrder(v[node - 'A'].first);
    cout << node;
    InOrder(v[node - 'A'].second);
}

void PostOrder(char node) {
    if (node == '.') return;

    PostOrder(v[node - 'A'].first);
    PostOrder(v[node - 'A'].second);
    cout << node;
}

int main() {
    int N;
    cin >> N;

    char root, left, right;
    while (N--) {
        cin >> root >> left >> right;
        v[root - 'A'].first = left;
        v[root - 'A'].second = right;
    }

    PreOrder('A');
    cout << '\n';

    InOrder('A');
    cout << '\n';

    PostOrder('A');
    cout << '\n';

    return 0;
}