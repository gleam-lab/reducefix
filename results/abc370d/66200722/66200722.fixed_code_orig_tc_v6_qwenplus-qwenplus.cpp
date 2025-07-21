#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<vector<bool>> has_wall(H, vector<bool>(W, true));

    auto valid = [&](int r, int c) {
        return 0 <= r && r < H && 0 <= c && c < W;
    };

    while (Q--) {
        int R, C;
        cin >> R >> C;
        R--;
        C--;

        if (has_wall[R][C]) {
            has_wall[R][C] = false;
        } else {
            // Up
            for (int r = R - 1; r >= 0; r--) {
                if (has_wall[r][C]) {
                    has_wall[r][C] = false;
                    break;
                }
            }
            // Down
            for (int r = R + 1; r < H; r++) {
                if (has_wall[r][C]) {
                    has_wall[r][C] = false;
                    break;
                }
            }
            // Left
            for (int c = C - 1; c >= 0; c--) {
                if (has_wall[R][c]) {
                    has_wall[R][c] = false;
                    break;
                }
            }
            // Right
            for (int c = C + 1; c < W; c++) {
                if (has_wall[R][c]) {
                    has_wall[R][c] = false;
                    break;
                }
            }
        }
    }

    int count = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (has_wall[i][j]) count++;
        }
    }

    cout << count << "\n";
}