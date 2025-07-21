#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<vector<bool>> wall(H + 2, vector<bool>(W + 2, true));
    auto destroy = [&](int r, int c) {
        if (r < 1 || r > H || c < 1 || c > W)
            return;
        wall[r][c] = false;
    };

    for (int i = 0; i <= H + 1; ++i)
        for (int j = 0; j <= W + 1; ++j)
            if (i == 0 || i == H + 1 || j == 0 || j == W + 1)
                wall[i][j] = false;

    while (Q--) {
        int R, C;
        cin >> R >> C;

        if (wall[R][C]) {
            destroy(R, C);
        } else {
            // up
            int r = R - 1, c = C;
            while (r >= 1 && !wall[r][c])
                --r;
            if (r >= 1)
                destroy(r, c);

            // down
            r = R + 1, c = C;
            while (r <= H && !wall[r][c])
                ++r;
            if (r <= H)
                destroy(r, c);

            // left
            r = R, c = C - 1;
            while (c >= 1 && !wall[r][c])
                --c;
            if (c >= 1)
                destroy(r, c);

            // right
            r = R, c = C + 1;
            while (c <= W && !wall[r][c])
                ++c;
            if (c <= W)
                destroy(r, c);
        }
    }

    long long ans = 0;
    for (int i = 1; i <= H; ++i)
        for (int j = 1; j <= W; ++j)
            ans += wall[i][j];

    cout << ans << '\n';
}