#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    
    // For each row, keep track of columns that have walls
    vector<set<int>> rows(h);
    // For each column, keep track of rows that have walls
    vector<set<int>> cols(w);
    
    // Initialize all cells to have walls
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            rows[i].insert(j);
            cols[j].insert(i);
        }
    }

    while (q--) {
        int r, c;
        cin >> r >> c;
        r--; c--;

        // Check if there's a wall at (r, c)
        if (cols[c].count(r) && rows[r].count(c)) {
            // Destroy the wall at (r, c)
            cols[c].erase(r);
            rows[r].erase(c);
        } else {
            // Destroy first wall above
            auto it = cols[c].lower_bound(r);
            if (it != cols[c].begin()) {
                it--;
                int wall_r = *it;
                cols[c].erase(it);
                rows[wall_r].erase(c);
            }

            // Destroy first wall below
            it = cols[c].lower_bound(r);
            if (it != cols[c].end()) {
                int wall_r = *it;
                cols[c].erase(it);
                rows[wall_r].erase(c);
            }

            // Destroy first wall to the left
            it = rows[r].lower_bound(c);
            if (it != rows[r].begin()) {
                it--;
                int wall_c = *it;
                rows[r].erase(it);
                cols[wall_c].erase(r);
            }

            // Destroy first wall to the right
            it = rows[r].lower_bound(c);
            if (it != rows[r].end()) {
                int wall_c = *it;
                rows[r].erase(it);
                cols[wall_c].erase(r);
            }
        }
    }

    // Count remaining walls
    long long ans = 0;
    for (int i = 0; i < h; ++i) {
        ans += rows[i].size();
    }
    cout << ans << endl;

    return 0;
}