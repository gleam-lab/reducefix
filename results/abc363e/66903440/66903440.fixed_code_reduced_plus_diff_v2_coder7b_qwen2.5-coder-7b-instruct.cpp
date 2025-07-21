#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 1005;
vector<vector<int>> A(MAXN, vector<int>(MAXN));

void solve() {
    int H, W, Y;
    cin >> H >> W >> Y;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    vector<vector<int>> sea_level(H, vector<int>(W, INT_MAX));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            sea_level[i][j] = min(sea_level[i][j], A[i][j]);
            if (i > 0) sea_level[i][j] = min(sea_level[i][j], sea_level[i - 1][j]);
            if (j > 0) sea_level[i][j] = min(sea_level[i][j], sea_level[i][j - 1]);
        }
    }

    for (int y = 1; y <= Y; ++y) {
        int count = 0;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (A[i][j] > y && sea_level[i][j] <= y) {
                    count++;
                }
            }
        }
        cout << count << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
    return 0;
}