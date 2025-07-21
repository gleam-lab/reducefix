#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w, q;
    cin >> h >> w >> q;

    vector<vector<bool>> walls(h + 2, vector<bool>(w + 2, true));
    vector<set<int>> row_walls(h + 2);
    vector<set<int>> col_walls(w + 2);

    // Initialize row_walls and col_walls
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            row_walls[i].insert(j);
            col_walls[j].insert(i);
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;

        if (walls[r][c]) {
            walls[r][c] = false;
            row_walls[r].erase(c);
            col_walls[c].erase(r);
        } else {
            // Check up
            auto it = col_walls[c].lower_bound(r);
            if (it != col_walls[c].begin()) {
                --it;
                walls[*it][c] = false;
                row_walls[*it].erase(c);
                col_walls[c].erase(it);
            }

            // Check down
            it = col_walls[c].lower_bound(r);
            if (it != col_walls[c].end()) {
                walls[*it][c] = false;
                row_walls[*it].erase(c);
                col_walls[c].erase(it);
            }

            // Check left
            it = row_walls[r].lower_bound(c);
            if (it != row_walls[r].begin()) {
                --it;
                walls[r][*it] = false;
                row_walls[r].erase(it);
                col_walls[*it].erase(r);
            }

            // Check right
            it = row_walls[r].lower_bound(c);
            if (it != row_walls[r].end()) {
                walls[r][*it] = false;
                row_walls[r].erase(it);
                col_walls[*it].erase(r);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) {
            if (walls[i][j]) {
                ++ans;
            }
        }
    }

    cout << ans << endl;
    return 0;
}