#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define all(x) x.begin(), x.end()

int main() {
    int H, W, Q;
    cin >> H >> W >> Q;
    vector<vector<bool>> grid(H, vector<bool>(W, true)); // Instead of sets, use a grid to track walls
    ll ans = H * W;

    rep2(i, 1, H + 1) {
        rep2(j, 1, W + 1) {
            if (grid[i-1][j-1]) {
                ans--; // Remove the initial wall at each cell
            }
        }
    }

    while (Q--) {
        int R, C;
        cin >> R >> C;
        R--; C--; // Convert to 0-based index

        if (grid[R][C]) { // If there is a wall at the bomb location
            grid[R][C] = false;
            ans--; // Remove the wall
        } else { // If there is no wall at the bomb location
            // Remove walls above and below this column
            rep(i, R + 1) {
                if (grid[i][C]) {
                    grid[i][C] = false;
                    ans--;
                }
            }
            rep(i, W - C) {
                if (grid[R][i + C]) {
                    grid[R][i + C] = false;
                    ans--;
                }
            }
            rep(i, H - R) {
                if (grid[i + R][C]) {
                    grid[i + R][C] = false;
                    ans--;
                }
            }
            rep(i, C + 1) {
                if (grid[R][i]) {
                    grid[R][i] = false;
                    ans--;
                }
            }
        }
    }

    cout << ans << endl;
    return 0;
}