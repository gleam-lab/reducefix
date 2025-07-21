#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(x) x.begin(), x.end()

int H, W, Q;
cin >> H >> W >> Q;

vector<vector<int>> row_left(H, vector<int>(W, -1)), row_right(H, vector<int>(W, W));
vector<vector<int>> col_top(W, vector<int>(H, -1)), col_bottom(W, H);
vector<vector<int>> grid(H, vector<int>(W));

rep(i, H) rep(j, W) {
    grid[i][j] = 1; // Assume there is a wall at each cell initially
}

ll ans = H * W;

for (ll itr = 0; itr < Q; ++itr) {
    ll R, C;
    cin >> R >> C;
    R--; C--;

    if (grid[R][C] == 1) {
        // Wall exists at (R, C), destroy it
        grid[R][C] = 0;
        ans--;
    } else {
        // Wall does not exist at (R, C), destroy walls in all four directions
        // Update row left and right
        rep(j, W) {
            // Update left
            if (j > 0 && col_top[j][R] != -1) {
                grid[R][j - 1] = 0;
                ans--;
            }
            // Update right
            if (j < W - 1 && col_top[j + 1][R] != -1) {
                grid[R][j + 1] = 0;
                ans--;
            }
        }

        // Update column top and bottom
        rep(i, H) {
            // Update top
            if (i > 0 && row_left[i][C] != -1) {
                grid[i - 1][C] = 0;
                ans--;
            }
            // Update bottom
            if (i < H - 1 && row_left[i + 1][C] != -1) {
                grid[i + 1][C] = 0;
                ans--;
            }
        }
    }
}

cout << ans << endl;