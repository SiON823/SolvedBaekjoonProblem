#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int T;
string X, Y, W;

int Xsize, Ysize, Wsize;
int Xidx, Yidx, Widx;
int leftX, rightX, leftY, rightY;

bool f;
int check[30][2];

pair<int, int> rngX, rngY;
vector< pair<int, int> > WX, WY;
vector< int > ans;

bool isPossible(int idx) { return check[idx][0] > 0 && check[idx][1] > 0; }

int main() {
    cin >> T;

    while (T--) {

        WX.clear();
        WY.clear();
        memset(check, 0, sizeof(check));

        cin >> X >> Y >> W;
        Xsize = X.length(); Ysize = Y.length(); Wsize = W.length();

        WX.push_back({ -1, 0 });
        WY.push_back({ -1, 0 });

        Widx = Xidx = Yidx = 0;
        while (Widx < Wsize) {
            while (X[Xidx] != W[Widx]) Xidx++;
            while (Y[Yidx] != W[Widx]) Yidx++;

            WX.push_back({ Xidx++, 0 });
            WY.push_back({ Yidx++, 0 });

            Widx++;
        }

        Widx = Wsize - 1; Xidx = Xsize - 1; Yidx = Ysize - 1;
        while (Widx >= 0) {
            while (Xidx >= 0 and X[Xidx] != W[Widx]) Xidx--;
            while (Yidx >= 0 and Y[Yidx] != W[Widx]) Yidx--;

            WX[Widx + 1].second = Xidx--;
            WY[Widx + 1].second = Yidx--;

            Widx--;
        }

        WX.push_back({ Xsize, Xsize });
        WY.push_back({ Ysize, Ysize });

        Widx = 0;
        f = 0;
        leftX = rightX = leftY = rightY = 0;
        while (Widx <= Wsize && !f) {
            rngX = { WX[Widx].first + 1, WX[Widx + 1].second - 1 };
            rngY = { WY[Widx].first + 1, WY[Widx + 1].second - 1 };

            while (leftX < rngX.first) {
                check[X[leftX] - 'a'][0]--;
                if (isPossible(X[leftX] - 'a')) f = 1;

                leftX++;
            }
            while (leftY < rngY.first) {
                check[Y[leftY] - 'a'][1]--;
                if (isPossible(Y[leftY] - 'a')) f = 1;

                leftY++;
            }

            while (rightX <= rngX.second) {
                check[X[rightX] - 'a'][0]++;
                if (isPossible(X[rightX] - 'a')) f = 1;

                rightX++;
            }
            while (rightY <= rngY.second) {
                check[Y[rightY] - 'a'][1]++;
                if (isPossible(Y[rightY] - 'a')) f = 1;

                rightY++;
            }
            Widx++;
        }
        ans.push_back(f);
    }

    for (int val : ans) cout << val << '\n';
}