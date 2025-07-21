#include <bits/stdc++.h>
using namespace std;

#define H 50000
#define W 50000

int row[H+1][W+1];
int col[H+1][W+1];

// æ¹åæ°ç»
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            row[i][j] = w;
            col[i][j] = h;
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;
        r++; c++;

        if (row[r][c]) {
            row[r][c]--;
            col[c][r]--;
        } else {
            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr > 0 && nr <= h && nc > 0 && nc <= w && row[nr][nc]) {
                    row[nr][nc]--;
                    col[nc][nr]--;
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            ans += row[i][j] + col[j][i];
        }
    }

    cout << ans << endl;

    return 0;
}