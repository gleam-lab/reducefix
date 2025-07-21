#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, q;
    cin >> h >> w >> q;

    vector<vector<bool>> coo(h + 2, vector<bool>(w + 2, true));
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

        if (coo[r][c]) {
            coo[r][c] = false;
            row[r].erase(c);
            col[c].erase(r);
        } else {
            // Up
            auto it = col[c].lower_bound(r);
            if (it != col[c].begin()) {
                --it;
                int i = *it;
                if (coo[i][c]) {
                    coo[i][c] = false;
                    row[i].erase(c);
                    col[c].erase(i);
                }
                ++it;
            }
            // Down
            it = col[c].lower_bound(r);
            if (it != col[c].end()) {
                int i = *it;
                if (coo[i][c]) {
                    coo[i][c] = false;
                    row[i].erase(c);
                    col[c].erase(i);
                }
            }
            // Left
            it = row[r].lower_bound(c);
            if (it != row[r].begin()) {
                --it;
                int j = *it;
                if (coo[r][j]) {
                    coo[r][j] = false;
                    row[r].erase(j);
                    col[j].erase(r);
                }
                ++it;
            }
            // Right
            it = row[r].lower_bound(c);
            if (it != row[r].end()) {
                int j = *it;
                if (coo[r][j]) {
                    coo[r][j] = false;
                    row[r].erase(j);
                    col[j].erase(r);
                }
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            ans += coo[i][j];
        }
    }

    cout << ans << endl;
    return 0;
}