#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;
    
    vector<map<int, bool>> cols(h), rows(w);
    
    rep(i, h) rep(j, w) {
        cols[i][j] = true;
        rows[j][i] = true;
    }
    
    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        if (!cols[r][c]) {
            // Find the nearest wall above
            if (r > 0 && cols[r-1][c]) {
                cols[r-1][c] = false;
                rows[c][r-1] = false;
            }
            // Find the nearest wall below
            if (r < h-1 && cols[r+1][c]) {
                cols[r+1][c] = false;
                rows[c][r+1] = false;
            }
            // Find the nearest wall to the left
            if (c > 0 && rows[c-1][r]) {
                rows[c-1][r] = false;
                cols[r][c-1] = false;
            }
            // Find the nearest wall to the right
            if (c < w-1 && rows[c+1][r]) {
                rows[c+1][r] = false;
                cols[r][c+1] = false;
            }
        } else {
            cols[r][c] = false;
            rows[c][r] = false;
        }
    }

    int ans = 0;
    rep(i, h) ans += count(cols[i].begin(), cols[i].end(), true);
    rep(j, w) ans += count(rows[j].begin(), rows[j].end(), true);

    cout << ans << '\n';
    return 0;
}