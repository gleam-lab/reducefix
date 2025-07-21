#include <bits/stdc++.h>
using namespace std;

int main() {
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
            auto it_up = col[c].lower_bound(r);
            if (it_up != col[c].begin()) {
                --it_up;
                coo[*it_up][c] = false;
                row[*it_up].erase(c);
                col[c].erase(it_up);
            }

            // Down
            auto it_down = col[c].lower_bound(r);
            if (it_down != col[c].end()) {
                coo[*it_down][c] = false;
                row[*it_down].erase(c);
                col[c].erase(it_down);
            }

            // Left
            auto it_left = row[r].lower_bound(c);
            if (it_left != row[r].begin()) {
                --it_left;
                coo[r][*it_left] = false;
                row[r].erase(it_left);
                col[*it_left].erase(r);
            }

            // Right
            auto it_right = row[r].lower_bound(c);
            if (it_right != row[r].end()) {
                coo[r][*it_right] = false;
                row[r].erase(it_right);
                col[*it_right].erase(r);
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