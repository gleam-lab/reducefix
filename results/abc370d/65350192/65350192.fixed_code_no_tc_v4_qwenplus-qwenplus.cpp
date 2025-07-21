#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    vector<set<int>> row_sets(h), col_sets(w);

    // Initialize all cells to have walls
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            row_sets[i].insert(j);
            col_sets[j].insert(i);
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        // Check if there is a wall at (r, c)
        if (row_sets[r].count(c)) {
            // Destroy the wall at (r, c)
            row_sets[r].erase(c);
            col_sets[c].erase(r);
        } else {
            // Up direction in column c
            auto it_up = col_sets[c].lower_bound(r);
            if (it_up != col_sets[c].begin()) {
                --it_up;
                int u = *it_up;
                col_sets[c].erase(it_up);
                row_sets[u].erase(c);
            }

            // Down direction in column c
            auto it_down = col_sets[c].lower_bound(r);
            if (it_down != col_sets[c].end()) {
                int d = *it_down;
                col_sets[c].erase(it_down);
                row_sets[d].erase(c);
            }

            // Left direction in row r
            auto it_left = row_sets[r].lower_bound(c);
            if (it_left != row_sets[r].begin()) {
                --it_left;
                int l = *it_left;
                row_sets[r].erase(it_left);
                col_sets[l].erase(r);
            }

            // Right direction in row r
            auto it_right = row_sets[r].lower_bound(c);
            if (it_right != row_sets[r].end()) {
                int ri = *it_right;
                row_sets[r].erase(it_right);
                col_sets[ri].erase(r);
            }
        }
    }

    // Count remaining walls
    int ans = 0;
    for (int i = 0; i < h; ++i) {
        ans += row_sets[i].size();
    }
    cout << ans << '\n';

    return 0;
}