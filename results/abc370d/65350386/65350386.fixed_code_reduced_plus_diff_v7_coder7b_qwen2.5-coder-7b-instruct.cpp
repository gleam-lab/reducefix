#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main(void) {
    int h, w, q;
    cin >> h >> w >> q;
    vector<vector<bool>> tate(h, vector<bool>(w, true)), yoko(h, vector<bool>(w, true));
    rep(qi, q) {
        int r, c;
        cin >> r >> c;
        r--; c--;
        if (tate[r][c]) {
            tate[r][c] = false;
            yoko[r][c] = false;
        } else {
            bool found = false;
            for (int i = r-1; i >= 0 && !found; i--) {
                if (!tate[i][c]) continue;
                tate[i][c] = false;
                yoko[i][c] = false;
                found = true;
            }
            for (int i = r+1; i < h && !found; i++) {
                if (!tate[i][c]) continue;
                tate[i][c] = false;
                yoko[i][c] = false;
                found = true;
            }
            for (int j = c-1; j >= 0 && !found; j--) {
                if (!yoko[r][j]) continue;
                yoko[r][j] = false;
                tate[r][j] = false;
                found = true;
            }
            for (int j = c+1; j < w && !found; j++) {
                if (!yoko[r][j]) continue;
                yoko[r][j] = false;
                tate[r][j] = false;
                found = true;
            }
        }
    }
    int ans = 0;
    rep(i,h) rep(j,w) {
        if (tate[i][j] || yoko[i][j]) ans++;
    }
    cout << ans << "\n";
    return 0;
}