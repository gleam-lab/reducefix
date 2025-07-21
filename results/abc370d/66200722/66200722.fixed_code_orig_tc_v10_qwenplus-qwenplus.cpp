#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<vector<bool>> has_wall(H, vector<bool>(W, true));
    auto valid = [&](int r, int c) {
        return r >= 0 && r < H && c >= 0 && c < W;
    };

    for (int q = 0; q < Q; ++q) {
        int R, C;
        cin >> R >> C;
        R--, C--;

        if (has_wall[R][C]) {
            has_wall[R][C] = false;
        } else {
            // up
            for (int r = R - 1; r >= 0; --r)
                if (has_wall[r][C]) {
                    has_wall[r][C] = false;
                    break;
                }
            // down
            for (int r = R + 1; r < H; ++r)
                if (has_wall[r][C]) {
                    has_wall[r][C] = false;
                    break;
                }
            // left
            for (int c = C - 1; c >= 0; --c)
                if (has_wall[R][c]) {
                    has_wall[R][c] = false;
                    break;
                }
            // right
            for (int c = C + 1; c < W; ++c)
                if (has_wall[R][c]) {
                    has_wall[R][c] = false;
                    break;
                }
        }
    }

    int count = 0;
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            count += has_wall[i][j];
    
    cout << count << endl;

    return 0;
}