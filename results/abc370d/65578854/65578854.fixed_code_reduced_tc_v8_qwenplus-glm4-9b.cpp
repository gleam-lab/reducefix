#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(x) x.begin(), x.end()

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<vector<int>> grid(H, vector<int>(W, 1)); // Using a 2D vector to represent the grid.
    ll ans = H * W;
    ll cnt = 0;

    auto destroy = [&](int r, int c) {
        cnt++;
        grid[r][c] = 0; // Remove the wall by setting it to 0.
    };

    auto destroy_row = [&](int r, int c) {
        for (int j = 0; j < W; j++) {
            if (grid[r][j] == 1) {
                destroy(r, j);
            }
        }
    };

    auto destroy_col = [&](int r, int c) {
        for (int i = 0; i < H; i++) {
            if (grid[i][c] == 1) {
                destroy(i, c);
            }
        }
    };

    rep(itr, Q) {
        int R, C;
        cin >> R >> C;
        R--; C--;
        if (grid[R][C]) {
            destroy(R, C);
        } else {
            // Destroy the walls in the row and column
            destroy_row(R, C);
            destroy_col(R, C);
        }
    }

    cout << ans - cnt << endl; // Output the number of remaining walls.
    return 0;
}