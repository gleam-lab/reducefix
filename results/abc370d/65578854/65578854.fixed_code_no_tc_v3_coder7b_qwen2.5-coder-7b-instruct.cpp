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

    auto destroyWall = [&](int r, int c) {
        if (grid[r][c]) {
            grid[r][c] = false;
            ans--;
        } else {
            for (int i = r - 1; i >= 0; --i) {
                if (grid[i][c]) {
                    grid[i][c] = false;
                    ans--;
                    break;
                }
            }
            for (int i = r + 1; i < H; ++i) {
                if (grid[i][c]) {
                    grid[i][c] = false;
                    ans--;
                    break;
                }
            }
            for (int j = c - 1; j >= 0; --j) {
                if (grid[r][j]) {
                    grid[r][j] = false;
                    ans--;
                    break;
                }
            }
            for (int j = c + 1; j < W; ++j) {
                if (grid[r][j]) {
                    grid[r][j] = false;
                    ans--;
                    break;
                }
            }
        }
    };

    while (Q--) {
        int R, C;
        cin >> R >> C;
        R--; C--;
        destroyWall(R, C);
    }

    cout << ans << endl;
    return 0;
}