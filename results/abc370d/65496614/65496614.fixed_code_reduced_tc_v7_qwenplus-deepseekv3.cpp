#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;

    vector<vector<bool>> wall(h + 2, vector<bool>(w + 2, true));
    vector<set<int>> row(h + 2);
    vector<set<int>> col(w + 2);

    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            row[i].insert(j);
            col[j].insert(i);
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;

        if (wall[r][c]) {
            // Destroy the wall at (r, c)
            wall[r][c] = false;
            row[r].erase(c);
            col[c].erase(r);
        } else {
            // Destroy the first walls in four directions
            // Up direction
            auto it = col[c].lower_bound(r);
            if (it != col[c].begin()) {
                --it;
                int i = *it;
                if (wall[i][c]) {
                    wall[i][c] = false;
                    row[i].erase(c);
                    col[c].erase(i);
                }
                ++it;
            }
            // Down direction
            it = col[c].upper_bound(r);
            if (it != col[c].end()) {
                int i = *it;
                if (wall[i][c]) {
                    wall[i][c] = false;
                    row[i].erase(c);
                    col[c].erase(i);
                }
            }
            // Left direction
            auto jt = row[r].lower_bound(c);
            if (jt != row[r].begin()) {
                --jt;
                int j = *jt;
                if (wall[r][j]) {
                    wall[r][j] = false;
                    row[r].erase(j);
                    col[j].erase(r);
                }
                ++jt;
            }
            // Right direction
            jt = row[r].upper_bound(c);
            if (jt != row[r].end()) {
                int j = *jt;
                if (wall[r][j]) {
                    wall[r][j] = false;
                    row[r].erase(j);
                    col[j].erase(r);
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            ans += wall[i][j];
        }
    }
    cout << ans << endl;

    return 0;
}