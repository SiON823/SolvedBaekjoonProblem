#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long int ll;

vector< pair<int, int> > cltime;

priority_queue< int, vector<int>, greater<int> > Q;

int greedy(int class_count) {
  
    Q.push(cltime[0].second);

    for (int i = 1; i < class_count; ++i) {
        Q.push(cltime[i].second);
        if (Q.top() <= cltime[i].first) {
            Q.pop();
        }
    }
    return Q.size();
}

int main() {

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int sta, end;
        cin >> sta >> end;
        cltime.push_back(make_pair(sta, end));
    }

    sort(cltime.begin(), cltime.end());

    cout << greedy(n) << endl;

}