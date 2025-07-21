#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(x) x.begin(), x.end()
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<vector<bool>> grid(H, vector<bool>(W, true));
    ll ans = H * W;

    auto erase = [&](int r, int c) {
        if (grid[r][c]) {
            ans--;
            grid[r][c] = false;
        }
    };

    rep(itr, Q) {
        int R, C;
        cin >> R >> C;
        R--; C--;

        if (grid[R][C]) {
            erase(R, C);
            continue;
        }

        // Check up
        for (int i = R - 1; i >= 0; --i) {
            if (grid[i][C]) {
                erase(i, C);
                break;
            }
        }

        // Check down
        for (int i = R + 1; i < H; ++i) {
            if (grid[i][C]) {
                erase(i, C);
                break;
            }
        }

        // Check left
        for (int j = C - 1; j >= 0; --j) {
            if (grid[R][j]) {
                erase(R, j);
                break;
            }
        }

        // Check right
        for (int j = C + 1; j < W; ++j) {
            if (grid[R][j]) {
                erase(R, j);
                break;
            }
        }
    }

    cout << ans << endl;
    return 0;
}