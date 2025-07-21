#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<int>> tate(h, vector<int>(w)), yoko(w, vector<int>(h));
    rep(i, h) rep(j, w) {
        tate[i][j] = 1; // Set all cells to have a wall
        yoko[j][i] = 1; // Set all cells to have a wall
    }
    
    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        if (tate[r][c] == 1) {
            tate[r][c] = 0; // Destroy the wall at (r, c)
            yoko[c][r] = 0; // Destroy the wall at (c, r)
        } else {
            // Search vertically for walls to destroy
            int up = r - 1;
            while (up >= 0 && tate[up][c] == 0) down = r + 1;
            if (up >= 0) tate[up][c] = 0;
            if (down < h) tate[down][c] = 0;
            
            // Search horizontally for walls to destroy
            int left = c - 1;
            while (left >= 0 && yoko[left][r] == 0) right = c + 1;
            if (left >= 0) yoko[left][r] = 0;
            if (right < w) yoko[right][r] = 0;
        }
    }
    
    // Count the number of remaining walls
    int ans = 0;
    rep(i, h) rep(j, w) {
        ans += tate[i][j] + yoko[j][i];
    }
    cout << ans << "\n";
    
    return 0;
}