#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<int>> tate(h + 1, vector<int>(w + 1, w));  // Use 1-based indexing
    vector<vector<int>> yoko(w + 1, vector<int>(h + 1, h));  // Use 1-based indexing

    rep(i, h) rep(j, w) {
        tate[i][j] = i;  // Wall is placed at the top edge of each cell
        yoko[j][i] = i;  // Wall is placed on the left edge of each cell
    }

    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        // If there's a wall at the position
        if (tate[c][r] == r) {
            tate[c][r] = -1;  // Remove the wall by setting the top edge index to -1
            yoko[r][c] = -1;  // Remove the wall by setting the left edge index to -1
        } else {
            // Find the first wall above and below
            int up = r - 1, down = r + 1, ans = 0;
            while (up >= 0) {
                if (tate[c][up] != -1) {
                    tate[c][up] = -1;
                    ans++;
                    up--;
                } else break;
            }
            up = r + 1;
            while (down < h) {
                if (tate[c][down] != -1) {
                    tate[c][down] = -1;
                    ans++;
                    down++;
                } else break;
            }
            // Find the first wall to the left and right
            int left = c - 1, right = c + 1;
            while (left >= 0) {
                if (yoko[r][left] != -1) {
                    yoko[r][left] = -1;
                    ans++;
                    left--;
                } else break;
            }
            right = c + 1;
            while (right < w) {
                if (yoko[r][right] != -1) {
                    yoko[r][right] = -1;
                    ans++;
                    right++;
                } else break;
            }
        }
    }

    int ans = 0;
    rep(i, h) rep(j, w) {
        if (tate[j][i] != -1) ans++;  // Count only the top walls that are not removed
    }
    rep(i, w) rep(j, h) {
        if (yoko[j][i] != -1) ans++;  // Count only the left walls that are not removed
    }
    cout << ans << "\n";
    return 0;
}